/*
	This simple piece of code simply turns your 64bit into a 32bit machine
	useful if you're cross-compiling for a weaker platform.

	Based on the program contained in the cross compiling hint by
	Daniel Baumann <danielbaumann@linuxmail.org>
	
	Originally Updated to 2.6.x series kernel by Roel Neefs.

	Updated to work with the 2.6.x series kernel driver standards
	by Jim Gifford.

	Updated to work with 2.6.16 and greater by Joe Ciccone.

	You will need to create a small Makefile for this module to 
	work.

	cat > Makefile << "EOF"
	obj-m += uname_hack.o
	EOF

	To compile as a module use the following command:

	make -C /usr/src/linux-{version} SUBDIRS=$PWD

*/

#if	0
#ifndef uname_hack_fake_machine
# define uname_hack_fake_machine "i486"
#endif
#endif

#ifndef uname_hack_fake_machine
# define uname_hack_fake_machine "ppc"
#endif

#include <linux/module.h>
#include <linux/init.h>
#include <linux/utsname.h>
#include <linux/version.h>

#if LINUX_VERSION_CODE >= 132630
# define uname_hack_uts_machine utsname()->machine
#else
# define uname_hack_uts_machine system_utsname.machine
#endif

#define uname_hack_uts_machine_len sizeof(uname_hack_uts_machine)

static char uname_hack_uts_machine_save[uname_hack_uts_machine_len];

static int __init uname_hack_init_module( void )
{
	memcpy(uname_hack_uts_machine_save, uname_hack_uts_machine, uname_hack_uts_machine_len);
	memset(uname_hack_uts_machine, uname_hack_uts_machine_len, '\0');
	memcpy(uname_hack_uts_machine, uname_hack_fake_machine, sizeof(uname_hack_fake_machine));
	return (0);
}

static void __exit uname_hack_cleanup_module( void )
{
	memcpy(uname_hack_uts_machine, uname_hack_uts_machine_save, uname_hack_uts_machine_len);
}

module_init(uname_hack_init_module);
module_exit(uname_hack_cleanup_module);

