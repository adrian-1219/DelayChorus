/*
  ==============================================================================

    KAPGainPanel.h
    Created: 4 Jan 2022 11:42:31am
    Author:  Adrian

  ==============================================================================
*/

#pragma once

#include "KAPPanelBase.h"
#include "KAPParameterSlider.h"

class KAPGainPanel
    : public KAPPanelBase
{
public:

    KAPGainPanel(KadenzeDelayChorusAudioProcessor* inProcessor);
    ~KAPGainPanel();

    void paint(juce::Graphics& g) override;

    void setParameterID(int inParameterID);

private:

    std::unique_ptr <KAPParameterSlider> mSlider;

};