/*
  ==============================================================================

    KAPParameterComboBox.cpp
    Created: 5 Jan 2022 4:20:58pm
    Author:  Adrian

  ==============================================================================
*/

#include "KAPParameterComboBox.h"

KAPParameterComboBox::KAPParameterComboBox(
    juce::AudioProcessorValueTreeState& stateToControl,
    const juce::String& parameterID)
    : juce::ComboBox(parameterID)
{
    mAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(
        stateToControl, parameterID, *this);
}
KAPParameterComboBox::~KAPParameterComboBox()
{

}