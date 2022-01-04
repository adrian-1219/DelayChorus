/*
  ==============================================================================

    KAPFxPanel.cpp
    Created: 4 Jan 2022 11:42:57am
    Author:  Adrian

  ==============================================================================
*/

#include "KAPFxPanel.h"

KAPFxPanel::KAPFxPanel(KadenzeDelayChorusAudioProcessor* inProcessor)
    : KAPPanelBase(inProcessor), mStyle(kKAPFxPanelStyle_Delay)
{
    setSize(FX_PANEL_WIDTH, FX_PANEL_HEIGHT);
}

KAPFxPanel::~KAPFxPanel()
{

}

void KAPFxPanel::paint(juce::Graphics& g)
{
    KAPPanelBase::paint(g);

    switch (mStyle)
    {
        case(kKAPFxPanelStyle_Delay): {
            g.drawFittedText("DELAY", 0, 0, getWidth(), getHeight(), juce::Justification::centred, 1);
        }break;
        case(kKAPFxPanelStyle_Chorus): {
            g.drawFittedText("CHORUS", 0, 0, getWidth(), getHeight(), juce::Justification::centred, 1);
        }break;
        default:
        case(kKAPFxPanelStyle_TotalNumStyles): {
            jassertfalse;
        }break;

    }
}

void KAPFxPanel::setFxPanelStyle(KAPFxPanelStyle inStyle)
{
    mStyle = inStyle;
}