/**
    MissileLauncher - Arduino library to work with USB MissileLauncher

    http://sudarmuthu.com/arduino/missilelauncher

    Requires v2.0 of USB Host Shield Library available at https://github.com/felis/USB_Host_Shield_2.0

   Copyright 2011  Sudar Muthu  (email : sudar@sudarmuthu.com)
/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <sudar@sudarmuthu.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer or coffee in return - Sudar
 * ----------------------------------------------------------------------------
 */

#include <Usb.h>

#ifndef MissileLauncher_H
#define MissileLauncher_H

// Different possible acctions
enum MissileLauncherActions {
    DOWN  = 1,  // down
    UP    = 2,    // up
    LEFT  = 4,  // left
    RIGHT = 8, // right
    FIRE  = 16, // fire
    STOP  = 32  // Stop
};


/**
 * The core MissileLauncher class
 */
class MissileLauncher : public USB {

public:

    // constructor
    MissileLauncher();

    // USB related methods

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void fire();
    void stop();

private:

    // methods
    void issueCommand(MissileLauncherActions);

    // variables
    uint8_t addr;
    uint8_t endPoint;
    uint8_t bmReqType;
    uint8_t bRequest;
    uint8_t wValLo;
    uint8_t wValHi;
    uint16_t wInd;
    uint16_t total;

};

#endif
