    /*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
NewProjectAudioProcessorEditor::NewProjectAudioProcessorEditor (NewProjectAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p), adsr (audioProcessor.apvts ), osc (audioProcessor.apvts, "OSC1WAVETYPE")
{

    addAndMakeVisible(adsr);
    addAndMakeVisible(osc);
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    //make adsr visible
    setSize (400, 300);
}

NewProjectAudioProcessorEditor::~NewProjectAudioProcessorEditor()
{
}

//==============================================================================
void NewProjectAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours::black);
}

void NewProjectAudioProcessorEditor::resized()
{
    // set adsr bounds
    osc.setBounds(10, 10, 100, 30);
    adsr.setBounds(getWidth() / 2, 0, getWidth() / 2, getHeight());
}