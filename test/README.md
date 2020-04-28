
### Testing notes

The tcl, expect, dejagnu, and check packages are needed to support testing of some packages.   tcl and check are part of opt or contrib.
expect and dejagnu ports can be found in this repository.

Some tests assume that /bin/sh is bash.   Crux uses dash instead so /bin/sh should be relinked to bash for testing.

Selected test results can be found under logs.
