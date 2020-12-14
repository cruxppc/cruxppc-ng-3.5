
12/14/20:  WIP rough draft

# Installing CRUX PPC via USB flash stick

The easiest CRUX PPC install media is CDROM.    However,  in cases
where the machines CD drive is not functioning properly, it is possible (but
tedious) to instead install CRUX PPC from USB flash stick.   

This document describes how to initialize the USB stick with the install image and boot it.

This document is only applicable to New World Apple machines.  Ostensibly, all 
New World machines will, with manual input, support booting from flash stick but
it is possible that the firmware in some machines does not support it.

## Materials needed:

A flash drive of at least 1Gig in size.   This procedure will overwrite any and all
data that is on the drive so make sure there is no important data on the drive prior
to beginning.

A computer with the hfsutils and mac-fdisk packages installed.   A CRUX PPC machine will already
have these tools installed.   On other OS's, you will have to install them using whatever
install tools that distro provides.

And of course the CRUXPPC install image.   This will have to be mounted on the machine that
you are preparing the USB stick on.   Most machines should support mounting the image but
if not, you may have to install a package or two to support doing so.

## Information needed:

You will have to determine the open firmware path for the USB flash drive.   This can be
done by inserting the USB stick into one of the USB ports and then rebooting the machine
and when you hear the startup chime, invoke the open firmware command line by pressing and 
holding the alt-system-o-f keys until the open firmware prompt appears.   Once the prompt
appears, release the keys.  Then type "dev / ls" and press return.

Examine the output displayed and find the path to the USB stick.   It will vary from 
machine to machine and will vary depending on which USB port the stick is inserted into.
Write the path down.   It will be something very similar to:

/pci@f2000000/usb1b,1/disk@1    (This is from an ibook g4 with the stick in the USB port nearest to the user).

This value has to be correct for the boot to work.   Write it down exactly.

Note which USB port you have the stick in, then take the USB stick out and put it in the machine
that you will be using to create the USB stick.   Once the stick is prepared, you will need to 
put it back in the very same Apple USB port that you used when determining the device path.


## Mount the install media

Now on the machine you will be using to initialize the USB stick on...

   Mount either the iso image or burned CDROM.   You can mount it whatever
you like but this example used /mnt/cruxppc:

mkdir /mnt/cruxppc

mount -o loop cruxppc.iso /mnt/cruxppc   (or whatever the .iso name is)

or 

mount /dev/cdrom /mnt/cruxppc   (if you are mounting the burned CD).

ls /mnt/cruxppc   (just to do a quick sanity check).



## Partion and format the flash drive


Paritioning and initializing the flash drive has the potential of wiping your
host machine.  A mistyped command or specifying the wrong device node can wipe your
drives.   Proceed cautiously and carefully and make sure you understand
what you are doing and that you are doing these operations to the USB drive, and not
to one of the important drives in your system.

Determine what device name your USB stick is.   It is very important that you
corectly identify it's name.   This example uses /dev/sdX but you will need to 
determine the actual name on your system.

Make sure the USB drive is not mounted.

umount /dev/sdX*

Usually optional:  Completely wipe any previous paritioning:

dd if=/dev/zero of=/dev/sdX bs=1M count=1
sync

(Theoretically you shouldn't have to reboot at this point but I usually do
 just for safety).

Partition the drive using mac-fdisk:

mac-fdisk /dev/sdX

The following commands will parition the USB stick as needed.

i
b
c
3p
100M
boot
c
4p
900M
rootfs
w
q

sync

(Theoretically you shouldn't have to reboot at this point but I usually do
 just for safety).

Now you have a USB stick with 4 paritions, 1 is the map, 2 is the open firmware
boot partition, 3 is the linux kernels parition, and 4 is the actual root filesystem.

Make the needed file systems:

mkfs.ext2 /dev/sdX3
mkfs.ext4 /dev/sdX4


## Create rootfs

mount partition 4 somewhere   (this example uses /mnt/rootfs):

mkdir /mnt/rootfs
mount /dev/sdX4 /mnt/rootfs

ls /mnt/rootfs  (just as a sanity check)

copy the install image root fs to the usb stick:

cd /mnt/cruxppc
find . -print |cpio -pdvum /mnt/rootfs

(If you are copying from an actual CDROM, it may speed things up a bit to do 
'find . -print >/tmp/list' then 'cat /tmp/list |cpio -pdvum /mnt/rootfs).

Adjust /etc/fstab:

Use vi or other editor to edit /mnt/cruxppc/etc/fstab and change the /dev/sr0 to 
the proper value for the USB stick when it is used on the Apple machine.  Typically 
on machines with only one hard drive, this will be /dev/sdb4.   If your machine
has two hard drives, it will typically be /dev/sdc4, and so on.   If it is wrong,
the USB stick will not be bootable but it is something that can be fixed without
too much difficulty.


Mount the USB stick boot partition and install the kernel:

mkdir /mnt/usbboot
mount /dev/sdX3 /mnt/usbboot
cd /mnt/usbboot
tar xvf /mnt/cruxppc/crux/kernel/cr*kern*.xz   (or whatever it's name is)
mv boot/vmlinux* vmcrux
rm -fr boot lib
sync
sync


Format and hmount the openfirmware boot partition:

hformat /dev/sdX2
hmount /dev/sdX2
hattr -b /dev/sdX2


Copy yaboot and yaboot.conf to the openfirmware boot parition:

hcopy /mnt/cruxppc/usr/lib/yaboot/yaboot :

Edit the yaboot.conf file in this directory and change the first
line to the open firmware path.  Then use hcopy to copy it:

hcopy yaboot.conf :
humount 
sync

Umount all USB stick partitions:
cd
umount /dev/sdX*
sync

The USB stick is now prepared.  Take it back to the Apple machine 
and put it back in exactly the same USB port as you started with:


Boot the USB stick:

Reboot (or poweron) the Apple machine and again enter open firmware
by using the alt-apple-o-f key sequance.

At the open firmware prompt do:

boot usb0/disk@1:2,\\yaboot

If that fails, try:

boot usb1/disk@1:2,\\yaboot

And the machine will then boot the CRUX PPC installer on USB stick
and the remainder of the install is the same as with booting from 
an install CD.

Note that rootdelay=15 and the boot up will be paused for 15 
seconds during startup.  This is to allow time for the USB stick
to be initialized and become available as a rootfs.  This should 
be plenty of delay but adjust it higher if you need to.
powered USB 

a CDROM.
Other than 
The rest of the installation is




