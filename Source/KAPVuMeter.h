/*
  ==============================================================================

    KAPVuMeter.h
    Created: 9 Jan 2022 7:31:51pm
    Author:  Adrian

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "PluginProcessor.h"

class KAPVuMeter : public juce::Component, public juce::Timer
{
public:
    KAPVuMeter(KadenzeDelayChorusAudioProcessor* inProcessor);
    ~KAPVuMeter();

    void paint(juce::Graphics& g) override;

    void timerCallback() override;

    void setParameterID(int inParameterID);

private:

    int mParameterID;

    float mCh0Level;
    float mCh1Level;

    KadenzeDelayChorusAudioProcessor* mProcessor;
};