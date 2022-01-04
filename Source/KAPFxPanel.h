/*
  ==============================================================================

    KAPFxPanel.h
    Created: 4 Jan 2022 11:42:57am
    Author:  Adrian

  ==============================================================================
*/

#pragma once

#include "KAPPanelBase.h"

enum KAPFxPanelStyle
{
    kKAPFxPanelStyle_Delay, 
    kKAPFxPanelStyle_Chorus, 
    kKAPFxPanelStyle_TotalNumStyles, 
};

class KAPFxPanel
    : public KAPPanelBase
{
public:

    KAPFxPanel(KadenzeDelayChorusAudioProcessor* inProcessor);
    ~KAPFxPanel();

    void paint(juce::Graphics& g) override;

    void setFxPanelStyle(KAPFxPanelStyle inStyle);

private:
    KAPFxPanelStyle mStyle;
};