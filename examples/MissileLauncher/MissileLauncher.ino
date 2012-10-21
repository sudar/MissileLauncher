/**
    MissileLauncher - A simple sketch that explains how to MissileLauncher Arduino library

    Requires 
    - v2.0 of USB Host Shield Library available at https://github.com/felis/USB_Host_Shield_2.0
    - MissileLauncher Arduino Library available at http://hardwarefun.com/projects/missile-launcher

    Stack the USB Host shield on top of Arduino and connect the USB Missile Launcher in the USB slot of the shield.
*/
   
/* Copyright 2011  Sudar Muthu  (email : sudar@sudarmuthu.com)
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <sudar@sudarmuthu.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer or coffee in return - Sudar
 * ----------------------------------------------------------------------------
 */

#include <MissileLauncher.h>
#include <Usb.h>

MissileLauncher ml;
void setup() {

    Serial.begin(115200);
    Serial.println("Start");

    if (ml.Init() == -1) {
        Serial.println("OSCOKIRQ failed to assert");
    }

    delay(200);
}

void loop() {

    ml.Task();

    if( ml.getUsbTaskState() == USB_STATE_RUNNING ) {
        Serial.println("Device Running");

        ml.moveUp();
        delay(1000);
        ml.stop();
        delay(200);

        ml.moveDown();
        delay(1000);
        ml.stop();
        delay(200);

        ml.moveLeft();
        delay(3000);
        ml.stop();
        delay(200);

        ml.moveRight();
        delay(3000);
        ml.stop();
        delay(200);

        ml.fire();
        delay(3000);
        ml.stop();
        delay(200);
    }//if( Usb.getUsbTaskState() == USB_STATE_RUNNING..
}
