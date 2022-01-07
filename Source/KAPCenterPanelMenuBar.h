/*
  ==============================================================================

    KAPCenterPanelMenuBar.h
    Created: 4 Jan 2022 11:41:39am
    Author:  Adrian

  ==============================================================================
*/

#pragma once

#include "KAPPanelBase.h"
#include "KAPParameterComboBox.h"
#include "KAPFxPanel.h"

class KAPCenterPanelMenuBar
    : public KAPPanelBase
{
public:

    KAPCenterPanelMenuBar(KadenzeDelayChorusAudioProcessor* inProcessor);
    ~KAPCenterPanelMenuBar();

    void addFxTypeComboBoxListener(juce::ComboBox::Listener* inListener);
    
    void removeFxTypeComboBoxListener(juce::ComboBox::Listener* inListener);



private:

    std::unique_ptr<KAPParameterComboBox> mFxTypeComboBox;

};