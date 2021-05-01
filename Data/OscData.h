/*
  ==============================================================================

    OscData.h
    Created: 29 Apr 2021 10:44:03pm
    Author:  brayd

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class OscData : public juce::dsp::Oscillator<float>
{
public:
    void prepareToPlay(juce::dsp::ProcessSpec& spec);
    void setWaveType(const int choice);
    void setWaveFrequency(const int midiNoteNumber);
    void getNextAudioBlock(juce::dsp::AudioBlock<float>& block);

private:

    juce::dsp::Oscillator<float> osc{ [](float x) { return std::sin(x); } };

};
