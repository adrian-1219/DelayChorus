/*
  ==============================================================================

    KAPCenterPanelMenuBar.cpp
    Created: 4 Jan 2022 11:41:39am
    Author:  Adrian

  ==============================================================================
*/

#include "KAPCenterPanelMenuBar.h"
#include "KAPParameters.h"


KAPCenterPanelMenuBar::KAPCenterPanelMenuBar(KadenzeDelayChorusAudioProcessor* inProcessor)
    : KAPPanelBase(inProcessor)
{
    setSize(CENTER_PANEL_MENU_BAR_WIDTH, CENTER_PANEL_MENU_BAR_HEIGHT);

    const int width = 85;

    mFxTypeComboBox = std::make_unique<KAPParameterComboBox>(
        mProcessor->parameters,
        KAPParameterID[kParameter_DelayType]);
    mFxTypeComboBox->setBounds(getWidth() - width, 0, width, getHeight());
    mFxTypeComboBox->addItem("DELAY", 1);
    mFxTypeComboBox->addItem("CHORUS", 2);
    mFxTypeComboBox->setSelectedItemIndex((int)mProcessor->getParameter(kParameter_DelayType), juce::dontSendNotification);
    addAndMakeVisible(*mFxTypeComboBox);
}
KAPCenterPanelMenuBar::~KAPCenterPanelMenuBar()
{

}

void KAPCenterPanelMenuBar::addFxTypeComboBoxListener(juce::ComboBox::Listener* inListener)
{
    mFxTypeComboBox->addListener(inListener);
}

void KAPCenterPanelMenuBar::removeFxTypeComboBoxListener(juce::ComboBox::Listener* inListener)
{
    mFxTypeComboBox->removeListener(inListener);
}

