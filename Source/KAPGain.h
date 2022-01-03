/*
  ==============================================================================

    KAPGain.h
    Created: 31 Dec 2021 9:47:53am
    Author:  Adrian

  ==============================================================================
*/

#pragma once

class KAPGain 
{
public:
    KAPGain();
    ~KAPGain();

    void process(float* inAudio, 
                 float inGain, 
                 float* outAudio, 
                 int inNumSamplesToRender);

private:

};