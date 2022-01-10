/*
  ==============================================================================

    KAPAudioHelpers.h
    Created: 31 Dec 2021 9:47:08am
    Author:  Adrian

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

#define kParameterSmoothingCoeff_Generic 0.04
#define kParameterSmoothingCoeff_Fine 0.002
#define kMeterSmoothingCoeff 0.2

const static int maxBufferDelaySize = 192000;

const static double kPI = juce::MathConstants<float>::pi;

inline float kap_linear_interp(float v0, float v1, float t) 
{
    return (1 - t) * v0 + t * v1;
}

inline double tanh_clip(double x)
{
    return x * (27 + x * x) / (27 + 9 * x * x);
}

inline float kap_denormalize(float inValue)
{
    float absValue = fabs(inValue);
    if (absValue < 1e-15) {
        return 0.0f;
    }
    else {
        return inValue;
    }
}

static inline float dBToNormalizedGain(float inValue)
{
    float inValuedB = juce::Decibels::gainToDecibels(inValue + 0.00001f);
    inValuedB = (inValuedB + 96.0f) / 96.0f;

    return inValuedB;
}


