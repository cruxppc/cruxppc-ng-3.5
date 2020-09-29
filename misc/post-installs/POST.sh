#!/bin/bash

# echo "running selected post-inst alls"
prt-get isinst adwaita-icon-theme && (/bin/bash -v adwaita-icon-theme/post-install)
prt-get isinst dbus && (/bin/bash -v dbus/post-install)
prt-get isinst glib && (/bin/bash -v glib/post-install)
prt-get isinst gtk3 && (/bin/bash -v gtk3/post-install)
prt-get isinst libglade && (/bin/bash -v libglade/post-install)
prt-get isinst libinput && (/bin/bash -v libinput/post-install)
prt-get isinst librsvg-compat && (/bin/bash -v librsvg-compat/post-install)
prt-get isinst shared-mime-info && (/bin/bash -v shared-mime-info/post-install)
prt-get isinst xorg-font-misc-misc && (/bin/bash -v xorg-font-misc-misc/post-install)
