

# Browsers

mainline crux provides the firefox browser as part of the install CD.   Firefox is very sluggish on 
powerpc so it was replaced by netsurf as part of the initial install.   Netsurfs performance is decent but
it does not work with a number of websites as it does not support all
the latest features of other browsers.

Firefox (an older version) is provided as a pre-built binary that you can download and install if you wish to use it.   But it is
quite slow.

Neither netsurf nor firefox is great.    Netsurf is speedy but does not support javascript and so some websites do not work.   
firefox supports more websites but it is quite slow.  



## netsurf

Lightweight browser.  Easy to build and works for general browsing but doesn't support everything.

## Arcticfox

ArcticFox builds now work and is added to the install CD.   It does not work with youtube videos and perhaps
other websites and consumes a large fraction of the CPU cycles.  But it seemes to be a better choice than firefox.

A port is provided to download the pre=built ArcticFox binary from the website and repackage it into a CRUX package.
It is not recommended to use the pre-built binary but it seems to function properly and may be useful for comparison 
and other experimental purposes.

## firefox

The version provided is 52.9.   Later versions have not been tried.   A build of firefox swaps like crazy even with 2Gig of RAM.   Later
versions require even more RAM during build so building a later version may not be feasible.

## dillo

Dillo is another easy to build and fairy lightweight browser.  It seems to function ok but haven't tried it much.
A port to build it can be found under experimental.

## seamonkey

Seamonkey seems to function (sluggish but works) but haven't tried it much.
A port to build it can be found under experimental.  Seamonkey build is 
multiple hours (best done overnight).


## midori

Not working!

Midori and it's dependency chain takes a very long time to build and the result does not function properly on powerpc.   It is 
likely a powerpc needed fix but until it is fixed, best not to spend the long time needed to build it.

## links and lynx

Both build and work ok if all you need is a text based browser.



## Others

Haven't much tried any other browsers besides those listed above.    Even the ones listed above have only been lightly used.

