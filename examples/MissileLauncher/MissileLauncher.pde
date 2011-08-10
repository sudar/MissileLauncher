#include <MissileLauncher.h>
#include <Usb.h>

MissileLauncher ml;
void setup() {

    Serial.begin( 115200 );
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

/*
//    byte addr = 0x41;
    uint8_t addr = 0x0A;
    byte data[1];

    //data[0] = 1; // down
    //data[0] = 2; // up
    //data[0] = 4; // left
//    data[0] = 8; // right
    //data[0] = 16; // fire

    delay (1000);

    Usb.Task();

    if( Usb.getUsbTaskState() == USB_STATE_RUNNING ) {
        Serial.println("Device Running");

//uint8_t USB::ctrlReq( uint8_t addr, uint8_t ep, uint8_t bmReqType, uint8_t bRequest, uint8_t wValLo, uint8_t wValHi,
	//				  uint16_t wInd, uint16_t total, uint16_t nbytes, uint8_t* dataptr, USBReadParser *p)

    Serial.println("Turn Down");
    data[0] = 1; // Down
    Usb.ctrlReq(addr, 0, 0x21, 0x09, 0x00, 0x02,
                0, 1, 1, data, NULL);

    delay (2000);

    Serial.println("Stop");

    data[0] = 32;

    Usb.ctrlReq(addr, 0, 0x21, 0x09, 0x00, 0x02,
                0, 1, 1, data, NULL);

    delay (1000);


    Serial.println("Turn Up");
    data[0] = 2; // Up
    Usb.ctrlReq(addr, 0, 0x21, 0x09, 0x00, 0x02,
                0, 1, 1, data, NULL);

    delay (2000);

    Serial.println("Stop");

    data[0] = 32;

    Usb.ctrlReq(addr, 0, 0x21, 0x09, 0x00, 0x02,
                0, 1, 1, data, NULL);



    Serial.println("Fire");
        data[0] = 16; // fire
    Usb.ctrlReq(addr, 0, 0x21, 0x09, 0x00, 0x02,
                0, 1, 1, data, NULL);

    delay (5000);

    Serial.println("Stop");

    data[0] = 32;

    Usb.ctrlReq(addr, 0, 0x21, 0x09, 0x00, 0x02,
                0, 1, 1, data, NULL);


    }//if( Usb.getUsbTaskState() == USB_STATE_RUNNING..
*/
}
