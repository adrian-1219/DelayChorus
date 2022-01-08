/*
  ==============================================================================

    KAPPresetManager.cpp
    Created: 7 Jan 2022 2:27:57pm
    Author:  Adrian

  ==============================================================================
*/

#include "KAPPresetManager.h"

#if JUCE_WINDOWS
static const juce::String directorySeperator = "\\";
#elif JUCE_MAC
static const juce::String directorySeperator = "/";
#endif

KAPPresetManager::KAPPresetManager(juce::AudioProcessor* inProcessor)
    : mCurrentPresetIsSaved(false), 
    mCurrentPresetName("Untitled"),
    mProcessor(inProcessor)
{
    const juce::String pluginName = (juce::String)mProcessor->getName();

    mPresetDirectory = (juce::File::getSpecialLocation(juce::File::userDesktopDirectory)).getFullPathName() + directorySeperator + pluginName;
    if (!juce::File(mPresetDirectory).exists()) {
        juce::File(mPresetDirectory).createDirectory();
    }

    storeLocalPreset();
}
KAPPresetManager::~KAPPresetManager()
{

}

void KAPPresetManager::getXmlForPreset(juce::XmlElement* inElement)
{
    const int numParameters = mProcessor->getNumParameters();

    for (int i = 0; i < numParameters; i++) {
        inElement->setAttribute(
            mProcessor->getParameterName(i),
            mProcessor->getParameter(i));
    }
}

void KAPPresetManager::loadPresetForXml(juce::XmlElement* inElement)
{
    mCurrentPresetXml = inElement;

    const int numParameters = mProcessor->getNumParameters();

    for (int i = 0; i < numParameters; i++) {
        const juce::String name = mCurrentPresetXml->getAttributeName(i);
        const float value = mCurrentPresetXml->getDoubleAttribute(name);

        for (int j = 0; j < mProcessor->getNumParameters(); j++) {
            if (mProcessor->getParameterName(j) == name) {
                mProcessor->setParameterNotifyingHost(j, value);
            }
        }

    }
}

int KAPPresetManager::getNumberOfPresets()
{
    return mLocalPresets.size();
}

juce::String KAPPresetManager::getPresetName(int inPresetIndex)
{
    return mLocalPresets[inPresetIndex].getFileNameWithoutExtension();
}

void KAPPresetManager::createNewPreset()
{
    const int numParameters = mProcessor->getNumParameters();

    for (int i = 0; i < numParameters; i++) {
        mProcessor->setParameterNotifyingHost(i, mProcessor->getParameterDefaultValue(i));
    }

    mCurrentPresetIsSaved = false;
    mCurrentPresetName = "Untitled";
}

void KAPPresetManager::savePreset()
{
    juce::MemoryBlock destinationData;
    mProcessor->getStateInformation(destinationData);

    mCurrentlyLoadedPreset.deleteFile();
    mCurrentlyLoadedPreset.appendData(destinationData.getData(), destinationData.getSize());
    mCurrentPresetIsSaved = true;
}

void KAPPresetManager::saveAsPreset(juce::String inPresetName)
{
    juce::File presetFile = juce::File(mPresetDirectory + directorySeperator + inPresetName + PRESET_FILE_EXTENSION);
    if (!presetFile.exists()) {
        presetFile.create();
    }
    else {
        presetFile.deleteFile();
    }
    juce::MemoryBlock destinationData;
    mProcessor->getStateInformation(destinationData);

    presetFile.appendData(destinationData.getData(), destinationData.getSize());
    mCurrentPresetIsSaved = true;
    mCurrentPresetName = inPresetName;

    storeLocalPreset();
}

void KAPPresetManager::loadPreset(int inPresetIndex)
{
    mCurrentlyLoadedPreset = mLocalPresets[inPresetIndex];

    juce::MemoryBlock presetBinary;

    if (mCurrentlyLoadedPreset.loadFileAsData(presetBinary)) {
        mCurrentPresetIsSaved = true;
        mCurrentPresetName = getPresetName(inPresetIndex);
        mProcessor->setStateInformation(presetBinary.getData(), (int)presetBinary.getSize());
    }

}

bool KAPPresetManager::getIsCurrentPresetSaved()
{
    return mCurrentPresetIsSaved; 
}

juce::String KAPPresetManager::getCurrentPresetName()
{
    return mCurrentPresetName;
}

void KAPPresetManager::storeLocalPreset()
{
    mLocalPresets.clear();
    for (juce::DirectoryIterator di(
        juce::File(mPresetDirectory),
        false,
        "*" + (juce::String)PRESET_FILE_EXTENSION,
        juce::File::TypesOfFileToFind::findFiles); di.next();) 
    {
        juce::File preset = di.getFile();
        mLocalPresets.add(preset);
    }

}