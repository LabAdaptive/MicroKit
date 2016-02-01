README file - dfu-util 0.8 binaries for win32

INSTALLATION:

Keep libusb-1.0.dll in the same directory as the dfu-util.exe or copy it
to the system library folder (e.g. C:\WINDOWS\SYSTEM32)

- or - use the dfu-util-static.exe which has libusb statically linked.

dfu-util uses libusb to access USB devices, and this version of libusb
uses WinUSB (a Microsoft Windows system driver installed by default in
Microsoft Vista and later versions). The USB device to be accessed
must therefore be registered with the WinUSB driver. This can easily be
done with the zadig tool from
https://sourceforge.net/projects/libwdi/files/zadig/

Plug in your device, run zadig.exe, select your device in the left field
and select WinUSB in the right field. You can now access your device from
any WinUSB or libusb based programs.

libusb also includes (experimental) support for the libusb-win32
and libusbK drivers, as alternatives to the WinUSB driver.

Please see https://github.com/libusb/libusb/wiki/Windows for more
information.

SOURCE CODE:

The sources for the libusb library (here distributed as libusb-1.0.dll)
can be found at http://libusb.info/

The sources for dfu-util.exe and dfu-suffix.exe can be found
at http://dfu-util.gnumonks.org/

See individual source files for full copyright information.
See enclosed COPYING file for distribution.

BUILDING:

The binaries were built using the enclosed build-mingw32-libusb.sh script,
on a Debian GNU/Linux 7 system.

The libusbx 1.0.19 release was compiled with:
make CFLAGS="-DWINVER=0x0501"

