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
    : public KAPPanelBase, 
    public juce::Button::Listener,
    public juce::ComboBox::Listener
{
public:

    KAPTopPanel(KadenzeDelayChorusAudioProcessor* inProcessor);
    ~KAPTopPanel();

    void paint(juce::Graphics& g) override;

    void buttonClicked(juce::Button* b) override;

    void comboBoxChanged(juce::ComboBox* comboBoxThatHasChanged) override;

private:

    void displaySaveAsPopup();

    void updatePresetComboBox();

    std::unique_ptr<juce::ComboBox> mPresetDisplay;

    std::unique_ptr <juce::TextButton> mNewPreset, mSavePreset, mSaveAsPreset;

};