/*
  ==============================================================================

    KAPGainPanel.cpp
    Created: 4 Jan 2022 11:42:31am
    Author:  Adrian

  ==============================================================================
*/

#include "KAPGainPanel.h"
#include "KAPHelperFunctions.h"
#include "KAPParameters.h"

KAPGainPanel::KAPGainPanel(KadenzeDelayChorusAudioProcessor* inProcessor)
    : KAPPanelBase(inProcessor)
{
    setSize(GAIN_PANEL_WIDTH, GAIN_PANEL_HEIGHT);
}
KAPGainPanel::~KAPGainPanel()
{

}

void KAPGainPanel::paint(juce::Graphics& g) {
    KAPPanelBase::paint(g);
    if (mSlider) {
        paintComponentLabel(g, mSlider);
    }
}

void KAPGainPanel::setParameterID(int inParameterID)
{
    mSlider = new KAPParameterSlider(mProcessor->parameters, KAPParameterID[inParameterID]);
    const int slider_size = 54;
    mSlider->setBounds(
        getWidth() * 0.5 - slider_size * 0.5, 
        getHeight() * 0.5 - slider_size * 0.5,
        slider_size,
        slider_size);
    addAndMakeVisible(*mSlider);
}