/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class GainPanPluginAudioProcessorEditor  : public juce::AudioProcessorEditor,
                                           public juce::Slider::Listener
{
public:
    GainPanPluginAudioProcessorEditor (GainPanPluginAudioProcessor&);
    ~GainPanPluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

    void sliderValueChanged(Slider* slider) override;

private:
    juce::Slider gainSlider;
    juce::Label gainLabel;
    juce::Slider panKnob;

    GainPanPluginAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GainPanPluginAudioProcessorEditor)
};
