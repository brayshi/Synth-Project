/*
  ==============================================================================

    SynthVoice.h
    Created: 18 Feb 2021 2:22:25pm
    Author:  brayd

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "SynthSound.h"
#include "Data/AdsrData.h"
#include "Data/OscData.h"

class SynthVoice : public juce::SynthesiserVoice
{
public:
    bool canPlaySound(juce::SynthesiserSound* sound) override;

    void startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPos) override;

    void stopNote(float velocity, bool allowTailOff) override;

    void pitchWheelMoved(int newPitchWheelValue) override;

    void controllerMoved(int controllerNumber, int newControllerValue) override;

    void prepareToPlay(double sampleRate, int samplesPerBlock, int outputChannels);

    void update(const float attack, const float decay, const float sustain, const float release);

    void renderNextBlock(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples) override;
    OscData& getOscillator() { return osc;  }

private:
    // double level;
    // double frequency;
    AdsrData adsr;
    juce::AudioBuffer<float> synthBuffer;

    OscData osc;
    juce::dsp::Gain<float> gain;
    bool isPrepared{ false };

};
