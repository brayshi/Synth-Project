/*
  ==============================================================================

    SynthSound.h
    Created: 18 Feb 2021 2:22:19pm
    Author:  brayd

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class SynthSound : public juce::SynthesiserSound
{
public :
    bool appliesToNote(int /*midiNoteNumbers*/) override { return true; }

    bool appliesToChannel(int /*midiChannel*/) override { return true; }
};
