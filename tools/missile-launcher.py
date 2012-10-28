'''
    Code to control USB Missile Lanuncher from desktop

    http://hardwarefun.com/projects/missile-launcher

    Requires the latest version of pyusb
   
/* Copyright 2011  Sudar Muthu  (email : sudar@sudarmuthu.com)
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <sudar@sudarmuthu.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer or coffee in return - Sudar
 * ----------------------------------------------------------------------------
 */
'''
import usb
import sys

device = usb.core.find(idVendor = 0x0a81, idProduct = 0x0701)

if device is None:
    print "Device not found"

if device.is_kernel_driver_active(0):
    device.detach_kernel_driver(0)

try:
    device.set_configuration()
    device.reset()
except usb.core.USBError as e:
    sys.exit("Could not set configuration: %s" % str(e))

endpoint = device[0][(0,0)][0]

#signal = 1 << 0 # down
#signal = 1 << 1 # up
signal = 1 << 2 # rotate left
#signal = 1 << 3 # rotate right
#signal = 1 << 4 # fire
#signal = 1 << 5 # stop

device.ctrl_transfer(0x21, 0x09, 0x0200, 0, [signal])
