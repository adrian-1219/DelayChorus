/*
  ==============================================================================

    KAPTopPanel.h
    Created: 4 Jan 2022 11:43:21am
    Author:  Adrian

  ==============================================================================
*/

#pragma once

#include "KAPPanelBase.h"

class KAPTopPanel
    : public KAPPanelBase
{
public:

    KAPTopPanel(KadenzeDelayChorusAudioProcessor* inProcessor);
    ~KAPTopPanel();

    void paint(juce::Graphics& g) override;

private:

};