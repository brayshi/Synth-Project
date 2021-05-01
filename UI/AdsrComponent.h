/*
  ==============================================================================

    AdsrComponent.h
    Created: 25 Apr 2021 11:54:02am
    Author:  brayd

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class AdsrComponent  : public juce::Component
{
public:
    AdsrComponent(juce::AudioProcessorValueTreeState& apvts);
    ~AdsrComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    void setSliderParams(juce::Slider& slider);
    juce::Slider attackSlider;
    juce::Slider sustainSlider;
    juce::Slider decaySlider;
    juce::Slider releaseSlider;

    using SliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;

    std::unique_ptr<SliderAttachment> attackSliderAttachment;
    std::unique_ptr<SliderAttachment> sustainSliderAttachment;
    std::unique_ptr<SliderAttachment> decaySliderAttachment;
    std::unique_ptr<SliderAttachment> releaseSliderAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AdsrComponent)
};
