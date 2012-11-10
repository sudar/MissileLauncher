/**
 * @mainpage Missile Launcher Arduino Library
 *
 * An Arduino library that allows you to control a USB MissileLauncher. 
 *
 * http://hardwarefun.com/projects/missile-launcher
 *
 * @note Requires v2.0 of USB Host Shield Library available at https://github.com/felis/USB_Host_Shield_2.0
 * @author Sudar <http://sudarmuthu.com> <http://hardwarefun.com>
 * @version 0.1
 */

/*
 * Copyright 2011  Sudar Muthu  (http://sudarmuthu.com)
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

/**
 * Enum to hold the different possible actions
 */
enum MissileLauncherActions {
    DOWN  = 1,  /*!< down */
    UP    = 2,  /*!< up */
    LEFT  = 4,  /*!< left */
    RIGHT = 8,  /*!< right */
    FIRE  = 16, /*!< fire */
    STOP  = 32  /*!< Stop */
};

/**
 * The core MissileLauncher class
 * 
 * @todo: Make the movement related methods inline
 */
class MissileLauncher : public USB {

public:

    /**
     * Default constructor
     */
    MissileLauncher();

    /**
     * Rotate upwards
     */
    void moveUp();

    /**
     * Rotate downwards
     */
    void moveDown();

    /**
     * Rotate Left
     */
    void moveLeft();

    /**
     * Rotate Right
     */
    void moveRight();

    /**
     * Fire the Missiles.
     *
     * Should call the stop method or any other movement methods to stop firing
     */
    void fire();

    /**
     * Stop the device
     */
    void stop();

private:

    /**
     * Send proper signal to the USB device based on command requested
     */
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
