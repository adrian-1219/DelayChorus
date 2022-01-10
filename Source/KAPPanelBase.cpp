/*
  ==============================================================================

    KAPPanelBase.cpp
    Created: 4 Jan 2022 11:40:59am
    Author:  Adrian

  ==============================================================================
*/

#include "KAPPanelBase.h"
#include "KAPInterfaceDefines.h"

KAPPanelBase::KAPPanelBase(KadenzeDelayChorusAudioProcessor* inProcessor)
    : mProcessor(inProcessor)
{

}
KAPPanelBase::~KAPPanelBase()
{
    //setLookAndFeel(nullptr);
}

void KAPPanelBase::paint(juce::Graphics& g)
{
    /* Old UI implementation
    g.setColour(juce::Colours::beige);
    g.fillAll();

    g.setColour(juce::Colours::black);
    g.drawRoundedRectangle(0, 0, getWidth(), getHeight(), 4, 2);
    */

    if (isMouseOver()) {
        // g.setColour(KAPColour_4);
        // g.fillAll();
    }

}

void KAPPanelBase::mouseEnter(const juce::MouseEvent& event)
{
    repaint();
}

void KAPPanelBase::mouseExit(const juce::MouseEvent& event)
{
    repaint();
}