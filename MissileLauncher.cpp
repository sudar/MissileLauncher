#include "MissileLauncher.h"

// constructor
MissileLauncher::MissileLauncher() : USB() {
    addr = 1; // Todo need to set it properly
}

void MissileLauncher::moveDown() {
    issueCommand(DOWN);
}

void MissileLauncher::moveUp() {
    issueCommand(UP);
}

void MissileLauncher::moveLeft() {
    issueCommand(LEFT);
}

void MissileLauncher::moveRight() {
    issueCommand(RIGHT);
}

void MissileLauncher::fire() {
    issueCommand(FIRE);
}

void MissileLauncher::stop() {
    issueCommand(STOP);
}

void MissileLauncher::issueCommand(MissileLauncherActions action) {
    byte data[1] = {action};

    ctrlReq(addr, 0, 0x21, 0x09, 0x00, 0x02, 0, 1, 1, data, NULL); //TODO move to constants
}
