/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
//Questo è il costruttore, e viene chiamato quando carichiamo il nostro plugin

NewProjectAudioProcessorEditor::NewProjectAudioProcessorEditor (NewProjectAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (500, 300);
    faderObject.addListener(this);
    faderObject.setSliderStyle(juce::Slider::LinearVertical);
    faderObject.setBounds(100, 50, 20, 200);
    faderObject.setTextBoxStyle(Slider::TextBoxBelow, 0, 70, 20);
    faderObject.setRange(0.0, 5.0);
    addAndMakeVisible(faderObject);
    
    
    //Drive
    driveObject.addListener(this);
    driveObject.setSliderStyle(juce::Slider::LinearVertical);
    driveObject.setBounds(200, 50, 20, 200);
    driveObject.setTextBoxStyle(Slider::TextBoxBelow, 0, 70, 20);
    driveObject.setRange(0.0, 9.0);
    addAndMakeVisible(driveObject);
    
    //Blend
    blendObject.addListener(this);
    blendObject.setSliderStyle(juce::Slider::LinearVertical);
    blendObject.setBounds(250, 50, 20, 200);
    blendObject.setTextBoxStyle(Slider::TextBoxBelow, 0, 70, 20);
    blendObject.setRange(0.0, 1.0);
    addAndMakeVisible(blendObject);
}

NewProjectAudioProcessorEditor::~NewProjectAudioProcessorEditor()
{
}

//==============================================================================
void NewProjectAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Gain", getLocalBounds(), juce::Justification::topLeft, 1);
}

void NewProjectAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void NewProjectAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
    if(slider == &faderObject){
        audioProcessor.gainMultiplier = slider-> getValue();
    }
    //gainMultiplier = slider;
    if(slider == &driveObject){
        audioProcessor.driveAmount = slider-> getValue();
    }
    
    if(slider == &blendObject){
        audioProcessor.blend = slider-> getValue();
    }
}
