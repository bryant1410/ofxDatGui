#include "ofApp.h"

/*
    All components instantiated outside of a gui
    https://github.com/braitsch/ofxDatGui @braitsch
*/

void ofApp::setup()
{
    int x = 140;
    int y = 100;
    int p = 40;
    ofSetWindowPosition(0, 0);

    ofxDatGuiComponent* component;

    component = new ofxDatGuiButton("button");
    component->setOrigin(x, y);
    component->onButtonEvent(this, &ofApp::onButtonEvent);
    components.push_back(component);

    y += component->getHeight() + p;
    component = new ofxDatGuiToggle("toggle", false);
    component->setOrigin(x, y);
    component->onButtonEvent(this, &ofApp::onButtonEvent);
    components.push_back(component);
    
    y += component->getHeight() + p;
    component = new ofxDatGuiMatrix("matrix", 21, true);
    component->setOrigin(x, y);
    component->onMatrixEvent(this, &ofApp::onMatrixEvent);
    components.push_back(component);

    y += component->getHeight() + p;
    component = new ofxDatGuiTextInput("text input", "# open frameworks #");
    component->setOrigin(x, y);
    component->onTextInputEvent(this, &ofApp::onTextInputEvent);
    components.push_back(component);

    y += component->getHeight() + p;
    component = new ofxDatGuiColorPicker("color picker", ofColor::fromHex(0xFFD00B));
    component->setOrigin(x, y);
    component->onColorPickerEvent(this, &ofApp::onColorPickerEvent);
    components.push_back(component);

    y = 100;
    x += component->getWidth() + p+60;

    component = new ofxDatGuiFRM();
    component->setOrigin(x, y);
    components.push_back(component);
    
    y += component->getHeight() + p;
    component = new ofxDatGuiSlider("slider", 0, 100, 50);
    component->setOrigin(x, y);
    component->onSliderEvent(this, &ofApp::onSliderEvent);
    components.push_back(component);
    
    y += component->getHeight() + p;
    component = new ofxDatGui2dPad("2d pad");
    component->setOrigin(x, y);
    component->on2dPadEvent(this, &ofApp::on2dPadEvent);
    components.push_back(component);

    y += component->getHeight() + p;
    ofxDatGuiDropdown* dropdown;
    vector<string> options = {"one", "two", "three", "four"};
    dropdown = new ofxDatGuiDropdown("dropdown menu", options);
    dropdown->setOrigin(x, y);
    dropdown->expand();
    dropdown->onDropdownEvent(this, &ofApp::onDropdownEvent);
    components.push_back(dropdown);
    
//  for(int i=0; i<components.size(); i++) components[i]->setOpacity(.25);
}

void ofApp::update()
{
    for(int i=0; i<components.size(); i++) components[i]->update();
}

void ofApp::draw()
{
    for(int i=0; i<components.size(); i++) components[i]->draw();
}

/*
    event listeners
*/

void ofApp::onButtonEvent(ofxDatGuiButtonEvent e)
{
    cout << "onButtonEvent: " << e.target->getLabel() << "::" << e.enabled << endl;
}

void ofApp::onSliderEvent(ofxDatGuiSliderEvent e)
{
    cout << "onSliderEvent: " << e.value << "::" << e.scale << endl;
}

void ofApp::onDropdownEvent(ofxDatGuiDropdownEvent e)
{
    cout << "onDropdownEvent: " << e.child << endl;
}

void ofApp::onMatrixEvent(ofxDatGuiMatrixEvent e)
{
    cout << "onMatrixEvent: " << e.child << "::" << e.enabled << endl;
}

void ofApp::onColorPickerEvent(ofxDatGuiColorPickerEvent e)
{
    cout << "onColorPickerEvent: " << e.color << endl;
}

void ofApp::on2dPadEvent(ofxDatGui2dPadEvent e)
{
    cout << "on2dPadEvent: " << e.x << "::" << e.y << endl;
}

void ofApp::onTextInputEvent(ofxDatGuiTextInputEvent e)
{
    cout << "onButtonEvent: " << e.text << endl;
}


