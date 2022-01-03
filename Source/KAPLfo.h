/*
  ==============================================================================

    KAPLfo.h
    Created: 31 Dec 2021 9:47:46am
    Author:  Adrian

  ==============================================================================
*/

#pragma once

#include "KAPAudioHelpers.h"

class KAPLfo
{
public:
    KAPLfo();
    ~KAPLfo();

    void reset();

    void setSampleRate(double inSampleRate);

    void process(float inRate, float inDepth, int inNumSample);

    float* getBuffer();
private:
    double mSampleRate;
    float mPhase;
    float mBuffer[maxBufferDelaySize];
};