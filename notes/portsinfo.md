
17Oct2019

## CRUX "ports" and CRUX-PPC

### General

I found the term "ports" a bit confusing when I first started using CRUX.  In
my experience and usage, a "port" was when you take a piece of software that
runs on one machine and make the changes needed to run that software on
a different machine.  But in the context of CRUX "port" means something a 
bit different than that.

In Crux  port is the script file ("Pkgfile") and other pieces (like maybe 
patches) needed to build a particular piece of software on a CRUX system.   
It is a 'recipe for building a package'.   It is analagous to an "ebuild" in
 gentoo, or sort of like an SRPM in Fedora although CRUX ports are 
quite a bit simpler than what you might find in other OSs.

### managing ports

"ports" are grouped together into repositories.   There are several
"official" repositories but also anyone can create their own ports and
setup their own repositories as they choose.

Initially after CRUX installation, there are no port repositories on
the machine.  The user populates their own local port repositories with
the command  "ports -u".  This command pulls a current snapshot of 
the core, opt and xorg respositories from the CRUX server and the 
/usr/ports directory is then populated.  Of course the network conntection
must be up for this to work

The contrib repository is not enabled by default.  If you want 
ports -u to also download the contrib ports, then adjust the contents
of /etc/ports and then run "ports -u".

NOTE:  In CRUX-PPC, the ppc specific ports are not automatically
populated by "ports -u".   For now, along with doing "ports -u", the 
CRUX-PPC user must obtain a copy of the ppc specific ports from this 
repository and copy them to /usr/ports.


### The Pkgfile

### Building packages.

There are two sets of tools that can be used for building packages:

1) The pkg-utils suite.
2) The prt-get utility.




