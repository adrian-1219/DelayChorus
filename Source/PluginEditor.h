/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "KAPMainPanel.h"
#include "KAPLookAndFeel.h"

//==============================================================================
/**
*/
class KadenzeDelayChorusAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    KadenzeDelayChorusAudioProcessorEditor (KadenzeDelayChorusAudioProcessor&);
    ~KadenzeDelayChorusAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    KadenzeDelayChorusAudioProcessor& audioProcessor;

    std::unique_ptr<KAPMainPanel> mMainPanel;
    std::unique_ptr<KAPLookAndFeel> mLookAndFeel;

    juce::Image mBackgroundImage;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (KadenzeDelayChorusAudioProcessorEditor)
};
