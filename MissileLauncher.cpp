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

#include "MissileLauncher.h"

// constructor
MissileLauncher::MissileLauncher() : USB() {
    addr = 1; // Todo need to change it if connected through a USB Hub
    endPoint = 0;
    bmReqType = 0x21;
    bRequest = 0x09;
    wValLo = 0x00;
    wValHi = 0x02;
    wInd = 0;
    total = 1;
}

// Move Down
void MissileLauncher::moveDown() {
    issueCommand(DOWN);
}

// Move Up
void MissileLauncher::moveUp() {
    issueCommand(UP);
}

// Move Left
void MissileLauncher::moveLeft() {
    issueCommand(LEFT);
}

// Move Right
void MissileLauncher::moveRight() {
    issueCommand(RIGHT);
}

// fire
void MissileLauncher::fire() {
    issueCommand(FIRE);
}

//stop
void MissileLauncher::stop() {
    issueCommand(STOP);
}

// private helper function
void MissileLauncher::issueCommand(MissileLauncherActions action) {
    byte data[1] = {action};

    ctrlReq(addr, endPoint, bmReqType, bRequest, wValLo, wValHi, wInd, total, sizeof(data)/sizeof(byte), data, NULL);
}
