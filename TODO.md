# TODO

05Nov2020

A high level list of what remains to be done for CRUX PPC 3.5

## Documentation 

Handbook has been updated.   More work is needed but it is now significantly better than previous versions.
Some howto documents would be useful for various configuration tasks.

## ports -u

Make changes needed for 'ports -u' to update the -ppc ports so that seperate
steps are no longer needed.


## Investigate/fix/test graphics

Radeon video generally works but has some issues.  Resolution seems off.   Also left most characters are not visible on some monitors.

ATI Rage video.   Xserver does not start.   Hopefully just an xorg.conf configuration problem but might be driver or kernel problems.

Nvidia video does not work well.   Screen resolution is way off.   This problem also happens with other distros.   Likely kernel or
driver problems to fix.

## Browsers

ArcticFox now functions and is part of the installation.

Performance improvements, testing, maybe bug fixes still needed.

## Clean up and update install CD image.

Keep install iso size under 700Meg so that it is compatible with older
machines which only have a CD drive.

Install ISO is now built from 3.5 packages.  

Identify/remove any graphics pkgs which are never applicable to powerpc.

Identify and add any additional packages that would be useful as part of the install CD.

Check setup.dependencies file for accuracy.

Figure out how to install CRUX PPC from USB instead of CD and write a 
howto or such on it.   Started.


## core/opt/contrib/xorg package building/testing.

A few packages from opt do not build properly.  

Build/Test some portion of contrib packages.

Provide selected subset of prebuilt packages from opt and contrib.

Keep -ppc ports up to date with mainline version changes.

Test as many packages as possible.  Particulary those that are provided on
the install CD.


## replace yaboot with grub

Initially this project re-uses the yaboot package from the Debian project as the bootloader.   yaboot has not been re-buildable from source for some time now.   So, although the yaboot binary still functions properly it cannot be changed if needed (although one could probably go back to a distro from about a decade ago and rebuild it in that way).   Some other ppc distros have started using grub instead of yaboot.    This task is very low priority and not likely to be addressed. 

