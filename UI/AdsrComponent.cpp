/*
  ==============================================================================

    AdsrComponent.cpp
    Created: 25 Apr 2021 11:54:02am
    Author:  brayd

  ==============================================================================
*/

#include <JuceHeader.h>
#include "AdsrComponent.h"

//==============================================================================
AdsrComponent::AdsrComponent(juce::AudioProcessorValueTreeState& apvts)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    using SliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;

    attackSliderAttachment = std::make_unique<SliderAttachment>(apvts, "ATTACK", attackSlider);
    sustainSliderAttachment = std::make_unique<SliderAttachment>(apvts, "SUSTAIN", sustainSlider);
    decaySliderAttachment = std::make_unique<SliderAttachment>(apvts, "DECAY", decaySlider);
    releaseSliderAttachment = std::make_unique<SliderAttachment>(apvts, "RELEASE", releaseSlider);

    setSliderParams(attackSlider);
    setSliderParams(decaySlider);
    setSliderParams(sustainSlider);
    setSliderParams(releaseSlider);

}

AdsrComponent::~AdsrComponent()
{
}

void AdsrComponent::paint (juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */
    /*
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (juce::Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (juce::Colours::white);
    g.setFont (14.0f);
    g.drawText ("AdsrComponent", getLocalBounds(),
                juce::Justification::centred, true);   // draw some placeholder text
    */
    g.fillAll(juce::Colours::black);
}

void AdsrComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    const auto bounds = getLocalBounds().reduced(10);
    const auto padding = 10;
    const auto sliderWidth = bounds.getWidth() / 4 - padding;
    const auto sliderHeight = bounds.getHeight() / 2;
    const auto sliderStartX = 0;
    const auto sliderStartY = bounds.getHeight() / 2;

    attackSlider.setBounds(sliderStartX, sliderStartY, sliderWidth, sliderHeight);
    decaySlider.setBounds(attackSlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);
    sustainSlider.setBounds(decaySlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);
    releaseSlider.setBounds(sustainSlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);
    // gainSlider.setBounds(getWidth() / 2 - 100, getHeight() / 2 - 50, 200, 100);

}

void AdsrComponent::setSliderParams(juce::Slider& slider) {
    slider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    slider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 25);
    addAndMakeVisible(slider);
}
