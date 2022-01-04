/*
  ==============================================================================

    KAPPanelBase.h
    Created: 4 Jan 2022 11:40:59am
    Author:  Adrian

  ==============================================================================
*/

#pragma once
#include "JuceHeader.h"
#include "PluginProcessor.h"
#include "KAPInterfaceDefines.h"

class KAPPanelBase
    : public juce::Component
{
public:
    KAPPanelBase(KadenzeDelayChorusAudioProcessor* inProcessor);
    ~KAPPanelBase();

    void paint(juce::Graphics& g) override;
protected:
    KadenzeDelayChorusAudioProcessor* mProcessor;
};