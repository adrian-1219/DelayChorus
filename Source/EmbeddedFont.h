/*
  ==============================================================================

    EmbeddedFont.h
    Created: 9 Jan 2022 6:28:37pm
    Author:  Adrian

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

class EmbeddedFont 
{
public:
    EmbeddedFont();
    ~EmbeddedFont();
    juce::Font& getFont(int fontNumber);

private:
    juce::Font mFont1;
    juce::Font mFont2;
    juce::Font mFont3;
};