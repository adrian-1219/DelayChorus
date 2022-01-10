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

void KAPPanelBase::mouseEnter(const juce::MouseEvent& event)
{
    repaint();
}

void KAPPanelBase::mouseExit(const juce::MouseEvent& event)
{
    repaint();
}

void KAPPanelBase::paint(juce::Graphics& g)
{

    if (isMouseOver()) {
        // Session 4 mouse hover assignment: 
        /*const juce::Colour hoverColour = 
            juce::Colour(juce::Colours::black).withAlpha(0.4f);

        g.setColour(hoverColour);
        g.fillAll();*/
    }

}
