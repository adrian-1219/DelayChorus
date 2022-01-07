/*
  ==============================================================================

    KAPDelay.cpp
    Created: 31 Dec 2021 9:48:02am
    Author:  Adrian

  ==============================================================================
*/

#include "KAPDelay.h"
#include "JuceHeader.h"
#include "KAPAudioHelpers.h"

KAPDelay::KAPDelay() 
:   mSampleRate(-1), 
    mFeedbackSample(0.0), 
    mTimeSmoothed(0),
    mDelayIndex(0)
{

}
KAPDelay::~KAPDelay()
{

}

void KAPDelay::setSampleRate(double inSampleRate)
{
    mSampleRate = inSampleRate;
}

void KAPDelay::reset()
{
    mTimeSmoothed = 0.0f;
    // zero out memory in buffer
    juce::zeromem(mBuffer, sizeof(double) * maxBufferDelaySize);
}

void KAPDelay::process(float* inAudio,
                       float inTime,
                       float inFeedback,
                       float inWetDry,
                       float inType,
                       float* inModulationBuffer,
                       float* outAudio,
                       int inNumSamplesToRender)
{
    // Calculate wet and dry values
    const float wet = inWetDry;
    const float dry = 1.0f - wet;

    // Map feedback value to be between 0 and 0.95
    // We want the feedback to decay complete eventually
    const float feedbackMapped = juce::jmap(inFeedback, 0.0f, 1.0f, 0.0f, 0.95f);

    for (int i = 0; i < inNumSamplesToRender; i++) {
        if ((int)inType == kKAPDelayType_Delay) {
            // Parameter smoothing for delay time
            // Smoothing is at sample level because it is being modulated very quickly
            mTimeSmoothed = mTimeSmoothed - kParameterSmoothingCoeff_Fine * (mTimeSmoothed - inTime);
        }
        else {
            // Modulate delay time for chorus effect
            const double delayTimeModulation = (0.003 + (0.002 * inModulationBuffer[i]));

            // Parameter smoothing for delay time
            // Smoothing is at sample level because it is being modulated very quickly
            mTimeSmoothed = mTimeSmoothed - kParameterSmoothingCoeff_Fine * (mTimeSmoothed - (delayTimeModulation));
        }

        // Calculate delay time in samples
        const double delayTimeInSamples = (mTimeSmoothed * mSampleRate);

        // Calculate interpolated sample
        const double sample = getInterpolatedSample(delayTimeInSamples); 

        // Add feedback to audio buffer
        mBuffer[mDelayIndex] = inAudio[i] + (mFeedbackSample * feedbackMapped);
        mFeedbackSample = sample;

        // Write mixed signal to out audio buffer
        outAudio[i] = (inAudio[i] * dry + sample * wet);

        // Increment delay index and wrap around if it is greater than delay buffer size
        mDelayIndex = mDelayIndex + 1;
        if (mDelayIndex >= maxBufferDelaySize) {
            mDelayIndex = mDelayIndex - maxBufferDelaySize;
        }

    }
}

double KAPDelay::getInterpolatedSample(float inDelayTimeInSamples)
{
    // Calculate read head (delay time in samples behind the delay index)
    double readPosition = (double)mDelayIndex - inDelayTimeInSamples;

    // Buffer boundary checks
    if (readPosition < 0.0f) {
        readPosition = readPosition + maxBufferDelaySize;
    }
    int index_y0 = (int)readPosition - 1;
    if (index_y0 <= 0) {
        index_y0 = index_y0 + maxBufferDelaySize;
    }
    int index_y1 = readPosition;
    if (index_y1 > maxBufferDelaySize) {
        index_y1 = index_y1 - maxBufferDelaySize;
    }

    // Calculate linear interp
    const float sample_y0 = mBuffer[index_y0];
    const float sample_y1 = mBuffer[index_y1];
    const float t = readPosition - (int)readPosition;

    float outSample = kap_linear_interp(sample_y0, sample_y1, t);

    return outSample;
}
