/*
  ==============================================================================

    KAPParameterSlider.cpp
    Created: 5 Jan 2022 4:20:48pm
    Author:  Adrian

  ==============================================================================
*/

#include "KAPParameterSlider.h"

KAPParameterSlider::KAPParameterSlider(
    juce::AudioProcessorValueTreeState& stateToControl,
    const juce::String& parameterID, 
    const juce::String& parameterLabel)
    : juce::Slider(parameterLabel)
{
    setSliderStyle(SliderStyle::RotaryHorizontalVerticalDrag);
    setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);

    setRange(0.0f, 1.0f, 0.001f);

    mAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        stateToControl, parameterID, *this);
}
KAPParameterSlider::~KAPParameterSlider()
{

}