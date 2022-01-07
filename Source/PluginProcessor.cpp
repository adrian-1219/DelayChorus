/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "KAPParameters.h"

//==============================================================================
KadenzeDelayChorusAudioProcessor::KadenzeDelayChorusAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : parameters(*this, nullptr, "PARAMETERS", createParameterLayout()),
    AudioProcessor(BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
    initializeDSP();

    mPresetManager = std::make_unique<KAPPresetManager>(this);
}

KadenzeDelayChorusAudioProcessor::~KadenzeDelayChorusAudioProcessor()
{
}

//==============================================================================
const juce::String KadenzeDelayChorusAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool KadenzeDelayChorusAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool KadenzeDelayChorusAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool KadenzeDelayChorusAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double KadenzeDelayChorusAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int KadenzeDelayChorusAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int KadenzeDelayChorusAudioProcessor::getCurrentProgram()
{
    return 0;
}

void KadenzeDelayChorusAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String KadenzeDelayChorusAudioProcessor::getProgramName (int index)
{
    return {};
}

void KadenzeDelayChorusAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void KadenzeDelayChorusAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    for (int i = 0; i < 2; i++) {
        mDelay[i]->setSampleRate(sampleRate);
        mLfo[i]->setSampleRate(sampleRate);
    }
}

void KadenzeDelayChorusAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
    for (int i = 0; i < 2; i++) {
        mDelay[i]->reset();
        mLfo[i]->reset();
    }
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool KadenzeDelayChorusAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void KadenzeDelayChorusAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);

        // Process input gain
        mInputGain[channel]->process(channelData,
                                getParameter(kParameter_InputGain), 
                                channelData, 
                                buffer.getNumSamples());
        

        // Turns the plugin into a chorus by enabling the LFO module on only one channel
        float rate = channel==0 ? getParameter(kParameter_ModulationRate): 0;

        // Process LFO
        mLfo[channel]->process(rate, 
                               getParameter(kParameter_ModulationDepth),
                               buffer.getNumSamples());

        // Process delay
        mDelay[channel]->process(channelData, 
                                 getParameter(kParameter_DelayTime),
                                 getParameter(kParameter_DelayFeedback),
                                 getParameter(kParameter_DelayWetDry),
                                 getParameter(kParameter_DelayType),
                                 mLfo[channel]->getBuffer(), 
                                 channelData,
                                 buffer.getNumSamples());

        // Process output gain
        mOutputGain[channel]->process(channelData,
                                      getParameter(kParameter_OutputGain),
                                      channelData,
                                      buffer.getNumSamples());
    }
}

//==============================================================================
bool KadenzeDelayChorusAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* KadenzeDelayChorusAudioProcessor::createEditor()
{
    return new KadenzeDelayChorusAudioProcessorEditor (*this);
}

//==============================================================================
void KadenzeDelayChorusAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void KadenzeDelayChorusAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

void KadenzeDelayChorusAudioProcessor::initializeDSP()
{
    // Initialize DSP modules for each channel
    for (int i = 0; i < 2; i++) {
        mInputGain[i] = std::make_unique<KAPGain>();
        mOutputGain[i] = std::make_unique<KAPGain>();
        mDelay[i] = std::make_unique<KAPDelay>();
        mLfo[i] = std::make_unique<KAPLfo>();
    }
}

juce::AudioProcessorValueTreeState::ParameterLayout KadenzeDelayChorusAudioProcessor::createParameterLayout()
{
    juce::AudioProcessorValueTreeState::ParameterLayout parameterLayout;
    for (int i = 0; i < kParameter_TotalNumParameters; i++) {
        parameterLayout.add(std::make_unique<juce::AudioParameterFloat>(
            KAPParameterID[i],
            KAPParameterID[i],
            juce::NormalisableRange<float>(0.0f, 1.0f),
            0.5f));
    }
    return parameterLayout;
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new KadenzeDelayChorusAudioProcessor();
}
