/**
  MissileLauncherFromSerial - A simple sketch that explains how to use MissileLauncher Arduino library

  The USB Missile Launcher will respond to the comments send from Arduino's Serial Monitor

  Requires 
        - v2.0 of USB Host Shield Library available at https://github.com/felis/USB_Host_Shield_2.0
        - MissileLauncher Arduino Library available at http://hardwarefun.com/projects/missile-launcher

  Circuit:
        Stack the USB Host shield on top of Arduino and connect the USB Missile Launcher in the USB slot of the shield.

  Author: 

    Sudar - <http://sudarmuthu.com> <http://hardwarefun.com>
    Refer to http://hardwarefun.com/projects/memory-free
 
  License:
     BeerWare ;)
*/
   
/* Copyright 2012  Sudar Muthu  (email : sudar@sudarmuthu.com)
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

    if (ml.Init() == -1) {
        Serial.println("OSCOKIRQ failed to assert");
    } else {
        Serial.println(F("Device Running. The following are the commands available"));
        Serial.println(F("L - Turn Left"));
        Serial.println(F("R - Turn Right"));
        Serial.println(F("U - Turn Up"));
        Serial.println(F("D - Turn Down"));
        Serial.println(F("F - Fire Missiles"));
        Serial.println(F("S - Stop"));
    }

    delay(200);
}

void loop() {

    char input = 0;

    ml.Task();

    if( ml.getUsbTaskState() == USB_STATE_RUNNING ) {

        if (Serial.available()) {
            input = Serial.read();

            switch (input) {
                case 'L':
                case 'l':
                    Serial.println(F("Moving Left"));
                    ml.moveLeft();            
                    break;

                case 'R':
                case 'r':
                    Serial.println(F("Moving Right"));
                    ml.moveRight();            
                    break;

                case 'U':
                case 'u':
                    Serial.println(F("Moving Up"));
                    ml.moveUp();            
                    break;

                case 'D':
                case 'd':
                    Serial.println(F("Moving Down"));
                    ml.moveDown();            
                    break;

                case 'F':
                case 'f':
                    Serial.println(F("Fire. Hide your self ;)"));
                    ml.fire();            
                    break;

                case 'S':
                case 's':
                    Serial.println(F("Stopping"));
                    ml.stop();            
                    break;

                default:
                    Serial.println(F("Sorry, I didn't understand your command"));
            }
        }
    }//if( Usb.getUsbTaskState() == USB_STATE_RUNNING..
}
