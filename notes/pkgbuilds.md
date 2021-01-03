
# Package building notes

Notes regarding package building

## Build machine

The typical build machine is a G4 but all packages provided on the install 
ISO are verified to build on a G3 machine with only 1Gig of RAM.    This 
is true even of the arcticfox package even though its build instructions 
lists 1.2G as the absolute minimum RAM required to build it.

Packages beyond those on the install ISO are typically buildable on a
machine with only 1 Gig of RAM but some of them might require more RAM to 
successfully build.    The more RAM the better.

The build machine should have swap space of at least a couple Gig.   Even
on a machine with 2G of RAM, building some packages will cause swapping.

For build space allow at least 40 to 50 Gig if building lots of packages.

## Build times (on a 1.25Ghz single core G4)

A rebuild of all packages on the install ISO requires about 48 hours of
compile time.   The longest is llvm (12 hours or so), followed by 
arcticfox (9 hours or so), and gcc, glibc, spidermonkey (several hours each).
The rest range from a couple of minutes to an hour or so in build time.

On a 700Mhz G3, build times are roughly 2x compared to the G4.

Of the remaining (not on ISO) packages, the longest straws are clang, 
rust, qt5, webkitgtk at about 24 hours or so each.    A number of other 
packages require several hours.   


## Build tools

prt-get is the suggested build tool.   It takes care of dependencies and
install scripts (make sure to adjust /etc/prt-get.conf as needed...)
prt-get is the easiest and most foolproof way to build packages.

The pkgutils can also be used but are more tedious since the user must
take care to meet dependencies, run install scripts, and ensure that
the -ppc specific ports are taken into account.

Personally, I find it easier to manage the package sources if the are all in
one spot rather than scattered throughout the ports trees.
So I create a directory /sources and point /etc/pkgmk.conf to use it for 
all package sources.   But that's just my preference.

Other useful changes to /etc/pkgmk.conf include using xz for package 
compression and ignoring the footprints.



## Dependencies and other build oddities

Several packages will not build unless docbook-xsl is installed.   This 
is the case even though they don't list docbook-xsl as a dependency.   If
you run into an error like "Can't load entity http:blah blah" and it looks 
like it wants an xml/xsl type of file, install docbook-xsl (and its deps)
and it may fix the problem.

The install of docbook-xsl does not take very long.   It may be beneficial 
to just go ahead and install it prior to building packages.

CRUX packages have a dependency list.  This list is useful as the minimum 
set of dependencies.    However, CRUX packages can wind up with more
dependencies than are explicity listed.  This happens when you build a
package and its configuration step finds another package happens to be
already installed that can be used as a dependency.   At that point, that 
other package becomes a dependendency even though it is not explicity listed
as a dependency.   There won't be a problem unless the package that is 
the implicit dependency gets removed or if you are installing pre-built
binaries.   If you are removing packages or installing prebuild binaries,
you may need to track down and fix these not-explicit dependencies.

If LXDE is installed, building spidermonkey will fail.   One of the LXDE 
packages interferes with the spidermonkey configuration step.   Weird, 
but if you want to rebuild spidermonkey, ensure that LXDE is not installed.


