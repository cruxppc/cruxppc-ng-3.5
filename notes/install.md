
# Installing CRUX PPC 3.5.  Notes and tips
12/02/20


This document is intended to be a supplment to the handbook and provides some additional explanation 
and tips for installing CRUX PPC


## General info

CRUX PPC does not require a network connection during the initial install.   All packages are 
installed from the local installation media, not the internet.   And in fact, it is
not possible (not easily anyway) to bring up the network connection in the install environment.
So, if you need additional materials for use during the install, you will need to copy them to 
a USB stick to make them available during the install.

If you are going to be installing ubuntu as well as CRUX on your system in a dual boot
configuration, install ubuntu first and then CRUX.   In my experience, the ubuntu installer
does not properly set up the boot loader when it detects a second OS and you are left with
a system that is not bootable at all.   So, wipe any existing CRUX install off, then install 
ubuntu and then install CRUX and then setup yaboot.conf for a dual boot configuration

The CRUX PPC install enviroment is a bootable CD, not a live CD.  /tmp is writable but you cannot
'modify' any other part of the install environment like you can with a live CD.

Make sure the system time is reasonbly correct prior to starting the install.  Older machines 
often have a dead battery and wrong clock setting.   Make sure the clock is set to a reasonable
value before starting the install.


## Install materials needed

You will need a blank CD (not DVD). 

Download the CRUX PPC iso image file.  Verify that your downloaded copy md5sum is correct.

If you will be using a WIFI adapter for network connection (e.g. a USB wifi adapter), download 
the linux-firmware package also.   The majority of the USB wifi adapters require linux-firmware
to be installed before they will function properly.   

If you will be building your initial kernel from source, download the kernel source that you
would like to use.   If you don't have a version preference, download kernel source 4.19.160.
If you are initially using the prebuilt kernel, then you don't need to download kernel
source.

If you are building a kernel from source with support for the builtin WIFI (airport or some such...), 
then you will also need to obtain the propreitary b43 firmware.   This can be done later but 
it easier to obtain it prior on an system that is already running and connected to the
internet and then copy it to a USB stick for use during the install.  You can install the b43-fwcutter tool on 
most distrubitions and use it to obtain the needed b43 firmware.   The b43fwscript file in this repository 
may be helpful.

Copy any needed firmwares and kernel source onto a USB flash stick.   The USB stick should
be in exfat, regular fat, or ext2,3 and 4 type of filesystem.


## Create and boot install CD


Burn the downloaded iso image onto the blank CD.   Insert the CD into the CD drive on the PowerMAc
and then (re)start the system.   Press and hold 'c' key until the system begins booting from the
CD.


## Create and boot install USB stick

TBA (Installing from USB not yet documented)


## Memtester and smartmontools

Memtester is provided and if desired, can be run from the install environment to help verify the 
integrity of the system memory.   

Smartmontools are provided as an installed package and after package installation, the integrity 
of the disk(s) can be checked with smartctl.   Ideally smartmontools would be available within 
the install enviroment but due to it's dependencies, smartmontools is not available until package 
installation is complete.

## partitioning/formatting hard drive

The Apple PPC machines use a partitioning scheme that is different from the partitioning that
you find on x86 machines.   You have to use a partitioning tool that supports the apple 
partition map.   mac-fdisk or parted will work but don't use the fdisk utility.  mac-disk is
the easiest to use IMO.

Personally, after I finish partitioning a drive, I reboot the machine.   It's probably not needed but
my paranoia tells me it's better to do it so I do. :)


## package installation

The setup step will take about 5 to 10 minutes to install the selected packages.


## building the kernel

   Kernel builds take a while.   About 6 hours on a faster G4 and 12+ hours on slower G3 machines.

   Even if you intend to build your own kernel, it is recommended to initially startup with the
prebuilt kernel and then build your own kernel at your first opportunity.   Building a kernel
within chroot is a bit tedious.

   The default kernel config enables builtin firmware.   These builtin firmware pieces must be
present in /lib/firmware or the build will fail.   So, you have to first get the needed pieces
of firmware and install them before starting.  Alternatively, you can modify the kernel config
to not require firmware but then the resulting kernel will not support the builtin wifi and maybe
other features as well.

   Some of the required firmware can be found in this repository.  (look under kernel/firmware).

   Because of licensing restrictions, the b43 firmware has to be obtained by the user and 
installed.   This can be done with the b43-fwcutter tool.   There is a script "b43fwscript"
which will download the needed files, run the tool and populate /lib/firmware with the needed
files.   There is no network support within chroot so this must either be done either prior 
and the b43 files brought in with a flash stick or it can be done after the system is initally
booted and network is up.

   The b43fwcutter tool can be installed and used on most distros (you probably will have to 
install it cause it usually isn't present by default).   The firmware is not specific to CRUX or
PPC and can be obtained with tools on most distros.   It's not something that can only be
done with CRUX PPC.

   Once any needed firmware is in /lib/firmware, configure and build your kernel with "make" and
then "make modules_install".   

   vmlinux is the kernel image.   Rename it to something better and copy it to your boot
directory.


## Configuring yaboot

   If you are building a single boot machine, then from within chroot, copy the 
/etc/sample.yaboot.conf to /etc/yaboot.conf and modify as you need.   Run 'mkofboot -v'
and then reboot into your CRUX linux install.

   If you are setting up dual booting, then you have to start with the other OSs yaboot.conf
and add to it.   You can do this either by rebooting into the other OS and modifying it's
yaboot.conf file or you can use the hfsutills (within chroot) to copy the other OSs yaboot.conf
into CRUX and modify it within CRUX.   To do so do:

hmount /dev/sda2   (typically sda2 but may be different on some machines)
hcopy :yaboot.conf /etc/yaboot.conf

   Add an entry for CRUX linux, run 'ybin' and then reboot.
