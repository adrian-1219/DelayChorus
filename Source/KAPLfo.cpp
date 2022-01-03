/*
  ==============================================================================

    KAPLfo.cpp
    Created: 31 Dec 2021 9:47:46am
    Author:  Adrian

  ==============================================================================
*/

#include "KAPLfo.h"

KAPLfo::KAPLfo() : mSampleRate(-1), mPhase(0)
{
    reset();
}

KAPLfo::~KAPLfo() 
{

}

void KAPLfo::reset()
{
    mPhase = 0.0f;
    juce::zeromem(mBuffer, sizeof(float) * maxBufferDelaySize);
}

void KAPLfo::setSampleRate(double inSampleRate)
{
    mSampleRate = inSampleRate;
}

void KAPLfo::process(float inRate, float inDepth, int inNumSamples)
{
    const float rate = juce::jmap(inRate, 0.0f, 1.0f, 0.01f, 10.0f);

    for (int i = 0; i < inNumSamples; i++) {
        // Move our phase forward
        mPhase = mPhase + (rate / mSampleRate);

        // Keep phase between 0 and 1
        if (mPhase > 1.0f) {
            mPhase = mPhase - 1.0f;
        }

        // Calculate LFO value at mPhase with given depth
        const float lfoPosition = sinf(mPhase * 2 * kPI) * inDepth;

        // Write LFO value to buffer
        mBuffer[i] = lfoPosition;
    }
}

float* KAPLfo::getBuffer()
{
    return mBuffer;
}