/*
  ==============================================================================

    EmbeddedFont.cpp
    Created: 9 Jan 2022 6:28:37pm
    Author:  Adrian

  ==============================================================================
*/

#include "EmbeddedFont.h"

EmbeddedFont::EmbeddedFont()
{
    mFont1 = juce::Font(juce::Typeface::createSystemTypefaceFor(
        BinaryData::FreeSansBold_ttf, BinaryData::FreeSansBold_ttfSize));
    mFont1.setHeight(12.0f);

    mFont2 = juce::Font(juce::Typeface::createSystemTypefaceFor(
        BinaryData::FreeSansBold_ttf, BinaryData::FreeSansBold_ttfSize));
    mFont2.setHeight(22.0f);

    mFont3 = juce::Font(juce::Typeface::createSystemTypefaceFor(
        BinaryData::FreeSansBold_ttf, BinaryData::FreeSansBold_ttfSize));
    mFont3.setHeight(48.0f);
}
EmbeddedFont::~EmbeddedFont()
{

}
juce::Font& EmbeddedFont::getFont(int fontNumber)
{
    if (fontNumber == 1) {
        return mFont1;
    }
    else if(fontNumber == 2) {
        return mFont2;
    }
    else {
        return mFont3; // returns font 3 if input is invalid
    }
}