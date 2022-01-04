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
    g.setColour(juce::Colours::whitesmoke);
    g.fillAll();

    g.setColour(juce::Colours::black);
    g.drawRect(0, 0, getWidth(), getHeight(), 1);

}