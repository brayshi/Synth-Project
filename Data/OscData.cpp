/*
  ==============================================================================

    OscData.cpp
    Created: 29 Apr 2021 10:44:03pm
    Author:  brayd

  ==============================================================================
*/

#include "OscData.h"

void OscData::prepareToPlay(juce::dsp::ProcessSpec& spec)
{
    prepare(spec);
}

void OscData::setWaveType(const int choice)
{
    switch (choice) {
    case 0:
        // sine
        initialise([](float x) { return std::sin(x); });
        break;
    case 1:
        // saw
        initialise([](float x) { return x / juce::MathConstants<float>::pi; });
        break;
    case 2:
        // square
        initialise([](float x) {return x < 0.0f ? -1.0f : 1.0f; });
        break;
    default:
        jassertfalse; // failed
        break;
    }
}

void OscData::setWaveFrequency(const int midiNoteNumber)
{
    setFrequency(juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber));
}

void OscData::getNextAudioBlock(juce::dsp::AudioBlock<float>& block)
{
    process(juce::dsp::ProcessContextReplacing<float>(block));
}