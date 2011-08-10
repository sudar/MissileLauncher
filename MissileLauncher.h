#include <Usb.h>

#ifndef MissileLauncher_H
#define MissileLauncher_H

enum MissileLauncherActions {
    DOWN  = 1,  // down
    UP    = 2,    // up
    LEFT  = 4,  // left
    RIGHT = 8, // right
    FIRE  = 16, // fire
    STOP  = 32  // Stop
};



class MissileLauncher : public USB {

public:

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
    byte addr;
}

#endif
