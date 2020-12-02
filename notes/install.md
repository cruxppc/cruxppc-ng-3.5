
# Installing CRUX PPC 3.5.  Notes and tips


This document is intended to be a supplment to the handbook and provides some additional explanation 
and tips for installing CRUX PPC


## Install materials needed

You will need a blank CD (not DVD).  (Installing from USB not yet documented)

Download the CRUX PPC iso image file.  Verify that your downloaded copy md5sum is correct.

If you will be using a WIFI adapter for network connection (e.g. a USB wifi adapter), download 
the linux-firmware package also.   The majority of the USB wifi adapters require linux-firmware
to be installed before they will function properly.   

If you will be building your initial kernel from source, download the kernel source that you
would like to use.   If you don't have a version preference, download kernel source 4.19.160.
If you are initially using the prebuilt kernel, then you don't need to download kernel
source.

If you are building a kernel from source with support for the builtin WIFI (airport or some such...), 
then you will also need to obtain the propreitary b43 firmware.   This can be done later during the
install but it may be easier to obtain it on an system that is already running and connected to the
internet.  You can install the b43-fwcutter tool on most distrubitions and use it to obtain the
needed b43 firmware.   The b43fwscript file in this repository may be helpful.

Copy the firmwares and kernel source onto a USB flash stick.   The USB stick should
be in exfat, regular fat, or ext2,3 and 4 type of filesystem.


## Create and boot install CD


Burn the downloaded iso image onto the blank CD.   Insert the CD into the CD drive on the PowerMAc
and then (re)start the system.   Press and hold 'c' key until the system begins booting from the
CD.


## Create and boot install USB stick

TBA


## Memtester and smartmontools

Memtester is provided and if desired, can be run from the install environment to help verify the 
integrity of the system memory.   

Smartmontools are provided as an installed package and after package installation, the integrity 
of the disk(s) can be checked with smartctl.   Due to it's dependencies, smartmontools is not
available until package installation is complete.

## partitioning/formatting hard drive

TBA


## package installation

The setup step takes about 5 to 10 minutes to complete.   


## building the kernel

TBA

## Configuring yaboot

TBA


