/*
  ==============================================================================

    AdsrData.h
    Created: 25 Apr 2021 11:54:45am
    Author:  brayd

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class AdsrData : public juce::ADSR
{
public:
    void updateADSR(const float attack, const float decay, const float sustain, const float release);

private:
    juce::ADSR::Parameters adsrParams;
};