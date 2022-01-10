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
    "InputGain",
    "Time",
    "Feedback",
    "WetDry",
    "Type",
    "OutputGain",
    "ModulationRate",
    "ModulationDepth"
};

static juce::String KAPParameterLabel[kParameter_TotalNumParameters] =
{
    "Input Gain",
    "Time",
    "Feedback",
    "Wet Dry",
    "Delay Type",
    "Output Gain",
    "Rate",
    "Depth"
};