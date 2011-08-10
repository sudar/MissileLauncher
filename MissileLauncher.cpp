#include "MissileLauncher.h"

// constructor
MissileLauncher::MissileLauncher() : USB() {
    addr = 1; // Todo need to set it properly
}

MissileLauncher::moveDown() {
    issueCommand(DOWN);
}

MissileLauncher::moveUp() {
    issueCommand(UP);
}

MissileLauncher::moveLeft() {
    issueCommand(LEFT);
}

MissileLauncher::moveRight() {
    issueCommand(RIGHT);
}

MissileLauncher::fire() {
    issueCommand(FIRE);
}

MissileLauncher::stop() {
    issueCommand(STOP);
}

MissileLauncher::issueCommand(MissileLauncherActions action) {
    byte data[1] = {action};

    ctrlReq(addr, 0, 0x21, 0x09, 0x00, 0x02, 0, 1, 1, data, NULL); //TODO move to constants
}
