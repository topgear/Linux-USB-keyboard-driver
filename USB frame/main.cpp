
/*static struct usb_driver skel_driver = {
name: "skeleton"；/*驱动程序的名称*/
probe: skel_probe； /*设备列举时被调用*/
disconnect: skel_disconnect； /*设备被卸载时被调用*/
};
static struct file_operation skel_fops={
{
owner:THIS_MODULE,
read:skel_read,
write:skel_write,
ioctl:skel_ioctl,
open:skel_open,
release:skel_release,
};
static void __exit usb_skel_exit(void)
{ /* deregister this driver with the USB subsystem */
usb_deregister(&skel_driver);
}
module_exit(usb_skel_exit);
/* table of devices that work with this driver */
static struct usb_device_id skel_table [] = {
{ USB_DEVICE(USB_SKEL_VENDOR_ID,
USB_SKEL_PRODUCT_ID) },
{ } /* Terminating entry */
};
MODULE_DEVICE_TABLE (usb, skel_table);
/* initialize the devfs node for this device and register it */
sprintf(name, "skel%d", skel->minor);
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/module.h>
#include <linux/input.h>
#include <linux/init.h>
#include <linux/usb.h>
#include <linux/kbd_ll.h>
/* 驱动程序版本信息*/
#define DRIVER_VERSION ""
#define DRIVER_AUTHOR " TGE HOTKEY "
#define DRIVER_DESC "USB HID Tge hotkey driver"
#define USB_HOTKEY_VENDOR_ID 0x07e4
#define USB_HOTKEY_PRODUCT_ID 0x9473
/*厂商和产品ID 信息就是/proc/bus/usb/devices 中看到的值，通过
cat/proc/bus/usb/devices 得到当前系统探测到的USB 总线上的设备信息。它包括Vendor、
ProdID、Product 等*/
MODULE_AUTHOR( DRIVER_AUTHOR );
MODULE_DESCRIPTION( DRIVER_DESC );
/*此结构来自内核中drivers/usb/usbkbd.c*/
struct usb_kbd {
struct input_dev dev;
struct usb_device *usbdev;
unsigned char new[8];
unsigned char old[8];
struct urb irq, led;
struct usb_ctrlrequest dr;
unsigned char leds, newleds;
char name[128];
int open;
};
static void usb_kbd_irq(struct urb *urb) /*urb 为USB 请求块*/
{
struct usb_kbd *kbd = urb->context;
int *new;
new = (int *) kbd->new;
if(kbd->new[0] == (char)0x01)
{
if(((kbd->new[1]>>4)&0x0f)!=0x7)
{
handle_scancode(0xe0,1);
handle_scancode(0x4b,1);
handle_scancode(0xe0,0);
handle_scancode(0x4b,0);
}
else
{ handle_scancode(0xe0,1);
handle_scancode(0x4d,1);
handle_scancode(0xe0,0);
handle_scancode(0x4d,0);
}
}
printk("new=%x %x %x %x %x %x %x %x"，
kbd->new[0],kbd->new[1],kbd->new[2],kbd->new[3],
kbd->new[4],kbd->new[5],kbd->new[6],kbd->new[7]);
}
static void *usb_kbd_probe(struct usb_device *dev, unsigned int ifnum, const struct
usb_device_id *id)
{
struct usb_interface *iface;
struct usb_interface_descriptor *interface;
struct usb_endpoint_descriptor *endpoint;
struct usb_kbd *kbd;
int pipe, maxp;
iface = &dev->actconfig->interface[ifnum];
interface = &iface->altsetting[iface->act_altsetting];
if ((dev->descriptor.idVendor != USB_HOTKEY_VENDOR_ID) ||
(dev->descriptor.idProduct != USB_HOTKEY_PRODUCT_ID) || (ifnum != 1))
{
return NULL;
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
