# MissileLauncher

MissileLauncher is an [Arduino](http://arduino.cc) library that can be used to operate [USB Missile Launcher's](http://www.thinkgeek.com/geektoys/warfare/8a0f/) from Arduino using [USB Host Shield](http://www.circuitsathome.com/products-page/arduino-shields/usb-host-shield-2-0-for-arduino/).

The library supports the following operations

*   Move Up
*   Move Down
*   Move Left
*   Move Right
*   Fire
*   Stop

## Examples

The library has a couple of example sketches that explains how to control the Missile Launcher

*   MissileLauncher.ino - Shows the normal way of using the library
*   MissileLauncherFromSerial.ino - Shows how you can read the command from Serial monitor and control the device

If you want to control the Missile Launcher from your desktop, then you can use the missile-launcher.py script found under the /tools directory

Also [checkout the article](http://hardwarefun.com/tutorials/controlling-usb-missile-launchers-using-arduino), that I have written about the library.

## Video

I have also uploaded a [video in youtube](http://youtu.be/hxFvpzAR4OI) which shows how you can control the device from Arduino.

## Dependency

This library requires the [USB Host Shield library](https://github.com/felis/USB_Host_Shield_2.0), without which it can't work.

## Setup

Stack the USB Host shield on top of Arduino and connect the USB Missile Launcher in the USB slot of the shield. 

More detailed documentation of the library can be found in its [homepage](http://hardwarefun.com/projects/missile-launcher)

## License

The source code of this library and the examples are released under "THE BEER-WARE" license.

I would, however, consider it a great courtesy if you could email me and tell me about your project and how this code was used, just for my own continued personal gratification :)

You can also find other ways to [make me happy](http://sudarmuthu.com/if-you-wanna-thank-me), if you liked this project.

##Support 

More details about this project and the support for this project can be found at its [homepage](http://hardwarefun.com/projects/missile-launcher).
