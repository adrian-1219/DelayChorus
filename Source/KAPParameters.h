/*
  ==============================================================================

    KAPParameters.h
    Created: 5 Jan 2022 10:11:04am
    Author:  Adrian

  ==============================================================================
*/

#pragma once

enum KAPParameter
{
    kParameter_InputGain = 0,
    kParameter_DelayTime,
    kParameter_DelayFeedback,
    kParameter_DelayWetDry,
    kParameter_DelayType,
    kParameter_OutputGain,
    kParameter_ModulationRate,
    kParameter_ModulationDepth,
    kParameter_TotalNumParameters
};

static juce::String KAPParameterID[kParameter_TotalNumParameters] =
{
    "Input Gain",
    "Time",
    "Feedback",
    "Wet Dry",
    "Type",
    "Output Gain",
    "Modulation Rate",
    "Modulation Depth"
};