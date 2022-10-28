#define up_btn 9 // left button
#define dn_btn 18 // right button
#define lt_btn 11 // left button
#define rt_btn 7 // right button

#include "SH1106Wire.h"
#include <Adafruit_NeoPixel.h>
#include "Nugget_Buttons.h"
#include "graphics.h"

SH1106Wire display(0x3C, 33, 35);
// Nugget_Buttons nuggButtons(up_btn,dn_btn,lt_btn,rt_btn);
extern Nugget_Buttons nuggButtons;
Adafruit_NeoPixel strip(1, 12, NEO_RGB + NEO_KHZ800);

void setup(){
    Serial.begin(115200);
    init();

    screenTester();
    buttonTester();
    // keyboardTester();

}

void loop() {
    Serial.println("Passed");
    // status();
}

void init() {
    strip.begin(); 

    display.init();
    display.flipScreenVertically();
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(DejaVu_Sans_Mono_10);

    strip.clear(); 
    strip.setPixelColor(0, strip.Color(0, 0, 0)); 
    strip.show();
    strip.show();
}

/******* Tester Functions *******/

void screenTester() {
    display.fillRect(0,0,128,64);
    display.display();
    delay(1000);
    display.clear();
}

void buttonTester() {
    bool buttonPass = false;
    String labels[] = {"UP","DOWN","LEFT","RIGHT"};
    for (uint8_t i=0; i<4; i++) {
        display.drawRect(10,(14*i)+3,10,10);
        display.drawString(23,(14*i)+3,labels[i]);
    }
    display.display();

    bool upp = false;
    bool dnp = false;
    bool ltp = false;
    bool rtp = false;
    while (!buttonPass) {
        uint8_t press = nuggButtons.getPress();
        if(nuggButtons.upPressed()) {
            display.fillRect(10,3,10,10);
            display.display();
            strip.setPixelColor(0, strip.Color(255,0, 0)); 
            strip.show(); strip.show();
            upp=true;
        }
        else if (nuggButtons.dnPressed()) {
            display.fillRect(10,17,10,10);
            display.display();
            strip.setPixelColor(0, strip.Color(0,0, 255)); 
            strip.show(); strip.show();
            dnp=true;
        }
        else if (nuggButtons.ltPressed()) {
            display.fillRect(10,28+3,10,10);
            display.display();
            strip.setPixelColor(0, strip.Color(255,255, 0)); 
            strip.show(); strip.show();
            ltp=true;
        }
        else if (nuggButtons.rtPressed()) {
            display.fillRect(10,42+3,10,10);
            display.display();
            strip.setPixelColor(0, strip.Color(0,255, 0)); 
            strip.show(); strip.show();
            rtp=true;
        }
        buttonPass= upp and dnp and ltp and rtp;
    }
    display.clear();
    display.display();
}

void keyboardTester() {

}

void status() {

}