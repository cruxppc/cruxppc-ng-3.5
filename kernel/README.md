
### Building the kernel.

Crux users normally configure and build their own kernel during Crux installation.   A
prebuilt kernel binary may be used to get started quickly but the user should then
configure and build their kernel as needed for their own needs.

Sample kernel configuration files are provided here.  pmac32_defconfig builds a kernel
with many drivers, filesystems and other features.   TBA: pmac32_smalldefconfig builds a minimal
kernel which provides a smaller set of features but is sufficient to boot on the PowerMac
32 bit machines.  

pmac32_smalldefconfig requires a few hours to build.   pmac32_defconfig requires more time to
build (best to let it build overnight.)  Your build time will vary depending on your machine.

Kernels take some time to build natively.   If you need to build kernels often, it may save 
time to build a powerpc cross compiler using crosstool-ng and then use a faster machine to 
do the kernel builds.

Selected firmware files that may be useful on a PowerMac machine are included under firmware.
Due to license restrictions, firmware needed for the builtin wifi device on apple machines
cannot be included in this repository.   If needed, said firmware can be obtained by the user 
by using the b43fw-cutter utility.  The b43fwscript provides an example of usage.   

At the present time the b43fwscript does not run properly on a CRUX PPC 3.5 system.
Until that is solved, the b43 firmware can be downloaded on most Linux systems and then
copied to the CRUX PPC kernel build area.

The Crux kernel typically does not make use of a ramdisk and so the needed firmware may be
added as a built in to the kernel.  If built in firmware is not desired, remove the built in 
firmware from the sample kernel config(s).

The user will need to download the appropriate linux kernel source (4.19.24 is suggested)
to the target.   

If using Crux PPC only as a chroot, then of course, no kernel build is required.


