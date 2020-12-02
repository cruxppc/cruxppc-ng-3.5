

# Desktops

CRUX does not normally provide a desktop.  The CRUX user selects a desktop and 
adds it themselves.  

A google search will find a number of repositories that support building a desktop for crux.   Some of them work, some don't.   


## LXDE

A repository for adding a simple LXDE desktop is included under ports.
LXDE is a lightweight desktop and works well if all you need is 
something simple.   An error message of "Could not connect.." initially 
pops up during startup but it seems benign and also occurs on x86 CRUX so 
is something to fix but does not seem to be anything crucial.

If you want lxde, modify prt-get.conf to enable it.   Starting with
alpha realease 2 The install CD may also provide pre-built lxde 
ports under /crux/lxde and can be manually installed with pkgadd.

LXDE can also be added by building from source.  It takes an hour
or two to build.

The middle mouse button provides the 'paste' function during cut and
pasting.  Not obvious at first glance...

At this time, LXDE is the recommended desktop for cruxppc if you need such a
thing.

## XFCE

A prototype XFCE can be found under experimental.   XFCE has more 
features than LXDE but is still theoretically fairly
lightweight. 

In practice though XFCE consumes a lot of CPU time even on an idle
PowerPC desktop and is quite sluggish.   This is not likely normal 
behaviour and something needs to be found and fixed.

Building an XFCE desktop from source requires several hours of 
build time.


## Other desktop

In theory, you should be able to add other desktops but haven't tried
anything other than LXDE and XFCE.
