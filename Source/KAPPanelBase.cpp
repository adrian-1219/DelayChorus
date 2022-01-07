/*
  ==============================================================================

    KAPPanelBase.cpp
    Created: 4 Jan 2022 11:40:59am
    Author:  Adrian

  ==============================================================================
*/

#include "KAPPanelBase.h"

KAPPanelBase::KAPPanelBase(KadenzeDelayChorusAudioProcessor* inProcessor)
    : mProcessor(inProcessor)
{

}
KAPPanelBase::~KAPPanelBase()
{

}

void KAPPanelBase::paint(juce::Graphics& g)
{
    g.setColour(juce::Colours::beige);
    g.fillAll();

    g.setColour(juce::Colours::black);
    g.drawRoundedRectangle(0, 0, getWidth(), getHeight(), 4, 2);

}