

# Desktops

CRUX does not normally provide a desktop.  The CRUX user selects a desktop and 
adds it themselves.  

A google search will find a number of repositories that support building a desktop for crux.   Some of them work, some don't.   


## LXDE

A repository for adding a simple LXDE desktop is included under ports.
LXDE is a lightweight desktop and works well if all you need is 
something simple.   An error message of "Could not connect.." initially 
pops up during startup but it seems benign and also occurs on x86 CRUX so 
is something to fix but not crucial.

If you want lxde, modify prt-get.conf to enable it.   The install CD 
may also provide pre-built lxde ports.  (See the handbook).

## XFCE

A snapshot of an XFCE repository can be found under experimental.   XFCE has more stuff than LXDE but is still fairly
lightweight.    The snapshot is not updated though, and it might be better to use the on-line repository to get the 
latest updates.

## Other desktop

In theory, you should be able to add other desktops but I haven't tried anything other than LXDE and XFCE.
