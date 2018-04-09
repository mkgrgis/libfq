Installing libfq
================

`libfq` should work on any UNIX-like system. Note that it requires
the Firebird header and client library which may be installed
as part of the Firebird binary package (e.g. on OS X), or which
need to be installed as separate packages (e.g. `firebird-devel`).

libfq can be installed from source in the usual way:

    ./configure
    make
    make install

The usual configuration options can be specified.

Note that `libfq` requires Firebird's `ibase.h` header file, which can
be in a non-standard location. Specify its path either with the
CFLAGS environment variable or the configure option `--with-ibase=DIR`.


Known ibase.h locations:
------------------------

OpenSuSE, CentOS/RedHat:

    /usr/include/firebird/

OS X:

    /Library/Frameworks/Firebird.framework/Versions/A/Headers/


Linking libfq
-------------

`libfq` depends on the Firebird client library 'libfbclient'; be sure
to link `libfq` before `libfbclient` (`-lfq -lfbclient`), and that libfbclient
is available to the linker (on OS X it is well hidden [1]).

[1] /Library/Frameworks/Firebird.framework/Versions/A/Libraries/