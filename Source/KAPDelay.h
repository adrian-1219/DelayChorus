/*
  ==============================================================================

    KAPDelay.h
    Created: 31 Dec 2021 9:48:02am
    Author:  Adrian

  ==============================================================================
*/

#pragma once

#include "KAPAudioHelpers.h"

class KAPDelay
{
public:
    KAPDelay();
    ~KAPDelay();

    void setSampleRate(double inSampleRate);

    void reset();

    void process(float* inAudio,
                 float inTime,
                 float inFeedback,
                 float inWetDry,
                 float* inModulationBuffer,
                 float* outAudio,
                 int inNumSamplesToRender);
private:
    double getInterpolatedSample(float inDelayTimeInSamples);

    double mSampleRate;
    double mBuffer[maxBufferDelaySize];
    double mFeedbackSample;

    float mTimeSmoothed;


    int mDelayIndex;

};