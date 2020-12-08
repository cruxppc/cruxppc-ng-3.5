
# Configuring up wifi

The Macs have two varieties of wifi.   The earliest version (often found on
G3 machines does not work (or at least I haven't been able to figure out
how to correctly configure it).  The later version (often found on G4
machines) is pretty easy to get working.   If you have a G3 machine, you
are probably better off using a USB wifi adapter instead of the builtin
wifi.

To bringup wifi in cruxppc:

1) If using a USB wifi adapter, install the linux-firmware package and
   depending on the adapter, you may need to rebuild kernel with support
   for your wifidevice enabled.   (The default kernel config has numerous
   wifi adapters enabled so there is a good chance a rebuild is not
   required).

   If using the Mac builtin wifi, linux-firmware should not be needed.

   Reboot after installing linux-firmware package.

2) Add password protected entries to /etc/wpa_supplicant.conf by using
   wpa_passphrase like so:

  "wpa_passphrase yourssidname yourwifipassword >>/etc/wpa_supplicant.conf"


   If the wifi has no password then add an wpa_supplicant.conf entry like:

   network={
	ssid="CoffeeShop_Public_WIFI"
        key_mgmt=NONE
   }
   

3) Modify the /etc/rc.d/wlan startup script as needed.  
   Specifically change the defintion of "DEV" to the
   name of appropriate interface.   The builtin wifi on ppc 
   machines is normally named "wlan0".  e.g. change:

   DEV=wlan0

   If your wifi is instead named "eth0", you may have the older 
   Mac wifi and it will require some as yet unknown further config
   changes.  

   If you are using a external wifi adaptor then your interface
   name will be something different.   Use ifconfig -a to help figure
   the proper interface name and then set DEV to that.  It will look 
   something like this:

   DEV=wlP1p16s24u1

   Setting DEV to the proper value is typically the only change you have
   to make to /etc/rc.d/wlan.


4) Add wlan to /etc/rc.conf to enable auto startup of wifi
   at boot.   It may display an ERROR during startup but should
   complete connection shortly after startup is complete.

   Alternatively, wifi can be brought up manually by running
   "/etc/rc.d/wlan start" as root.


After a few seconds ater start, WIFI should be up.

