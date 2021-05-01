/*
  ==============================================================================

    OscComponent.cpp
    Created: 29 Apr 2021 11:04:21pm
    Author:  brayd

  ==============================================================================
*/

#include <JuceHeader.h>
#include "OscComponent.h"

//==============================================================================
OscComponent::OscComponent(juce::AudioProcessorValueTreeState& apvts, juce::String waveSelectorId)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    juce::StringArray choices{ "Sine", "Saw", "Square" };
    oscWaveSelector.addItemList(choices, 1); // has to be one for some reason? not sure why the offset starts here instead of 0 but whatever
    addAndMakeVisible(oscWaveSelector);

    oscWaveSelectorAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(apvts, waveSelectorId, oscWaveSelector);

}

OscComponent::~OscComponent()
{
}

void OscComponent::paint (juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll(juce::Colours::black);
}

void OscComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    oscWaveSelector.setBounds(0, 0, 90, 20);
}
