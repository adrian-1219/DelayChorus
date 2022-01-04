/*
  ==============================================================================

    KAPTopPanel.cpp
    Created: 4 Jan 2022 11:43:21am
    Author:  Adrian

  ==============================================================================
*/

#include "KAPTopPanel.h"

KAPTopPanel::KAPTopPanel(KadenzeDelayChorusAudioProcessor* inProcessor)
    : KAPPanelBase(inProcessor)
{
    setSize(TOP_PANEL_WIDTH, TOP_PANEL_HEIGHT);
}
KAPTopPanel::~KAPTopPanel()
{

}
void KAPTopPanel::paint(juce::Graphics& g)
{
    KAPPanelBase::paint(g);
    g.drawFittedText("KADENZE AUDIO PLUGIN", 0, 0, getWidth() - 10, getHeight(), juce::Justification::centredRight, 1);
}