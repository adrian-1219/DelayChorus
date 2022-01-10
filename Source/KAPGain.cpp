/*
  ==============================================================================

    KAPGain.cpp
    Created: 31 Dec 2021 9:47:53am
    Author:  Adrian

  ==============================================================================
*/

#include "KAPGain.h"
#include "KAPAudioHelpers.h"

KAPGain::KAPGain() 
    : mOutputSmoothed(0)
{

}
KAPGain::~KAPGain() 
{

}

void KAPGain::process(float* inAudio, float inGain, float* outAudio, int inNumSamplesToRender) 
{
    // Map decibels to gain
    float gainMapped = juce::jmap(inGain, 0.0f, 1.0f, -24.0f, 24.0f);
    gainMapped = juce::Decibels::decibelsToGain(gainMapped, -24.0f);

    // Process each sample in the audio buffer
    for (int i = 0; i < inNumSamplesToRender; i++) {
        outAudio[i] = inAudio[i] * gainMapped;
    }

    float absValue = fabs(outAudio[0]);
    mOutputSmoothed = kMeterSmoothingCoeff * (mOutputSmoothed - absValue) + absValue;
}

float KAPGain::getMeterLevel()
{
    return mOutputSmoothed;
}