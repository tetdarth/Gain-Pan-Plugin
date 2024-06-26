/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
GainPanPluginAudioProcessorEditor::GainPanPluginAudioProcessorEditor (GainPanPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // gainSlider
    gainSlider.setSliderStyle(juce::Slider::LinearVertical);
    gainSlider.setRange(-60.0f, 6.0f, 0.1);
    gainSlider.setValue(0.0f);
    gainSlider.setSkewFactor(3.0, false);
    gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 100, 20);
    gainSlider.setTextValueSuffix("dB");
    gainSlider.addListener(this);
    addAndMakeVisible(gainSlider);
    gainLabel.setText("Gain", dontSendNotification);
    gainLabel.setFont(24.0f);
    gainLabel.attachToComponent(&gainSlider, false);
    gainLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(gainLabel);

    // panKnob
    panKnob.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    panKnob.setRange(0.0f, 1.0f, 0.01);
    panKnob.setValue(0.5f);
    panKnob.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 100, 20);
    panKnob.addListener(this);
    addAndMakeVisible(panKnob);

    setSize (260, 450);
}

GainPanPluginAudioProcessorEditor::~GainPanPluginAudioProcessorEditor()
{
}

//==============================================================================
void GainPanPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours::grey);
}

void GainPanPluginAudioProcessorEditor::resized()
{
    gainSlider.setBounds(getWidth()/2 - 50, getHeight()/2 -150, 100, 240);
    panKnob.setBounds(getWidth() / 2 - 50, getHeight() / 2 + 100, 100, 100);
}

void GainPanPluginAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
    if (slider == &gainSlider) audioProcessor.gainValue = gainSlider.getValue();
    if (slider == &panKnob) audioProcessor.panValue = panKnob.getValue();
}