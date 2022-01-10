/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"



//==============================================================================
KadenzeDelayChorusAudioProcessorEditor::KadenzeDelayChorusAudioProcessorEditor (KadenzeDelayChorusAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize(MAIN_PANEL_WIDTH, MAIN_PANEL_HEIGHT);

    mLookAndFeel = std::make_unique<KAPLookAndFeel>();
    setLookAndFeel(mLookAndFeel.get());
    juce::LookAndFeel::setDefaultLookAndFeel(mLookAndFeel.get());

    mMainPanel = std::make_unique<KAPMainPanel>(&audioProcessor);
    addAndMakeVisible(*mMainPanel);

    mBackgroundImage = juce::ImageCache::getFromMemory(BinaryData::kadenze_bg_png,
        BinaryData::kadenze_bg_pngSize);

}

KadenzeDelayChorusAudioProcessorEditor::~KadenzeDelayChorusAudioProcessorEditor()
{
    juce::LookAndFeel::setDefaultLookAndFeel(nullptr);
    setLookAndFeel(nullptr);
    mLookAndFeel.reset();
}

//==============================================================================
void KadenzeDelayChorusAudioProcessorEditor::paint (juce::Graphics& g)
{
    // Draw custom background
    g.drawImage(mBackgroundImage, getLocalBounds().toFloat());
}

void KadenzeDelayChorusAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
