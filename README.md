# CC2531 Serial->USB AT-Command Terminal with 6LoWPAN Connectivity

## Goal of this project

The goal is to implement an AT-Command-set styled (See [Hayes command set](https://en.wikipedia.org/wiki/Hayes_command_set)) Firmware on the Texas Instruments [CC2531 USB Evaluation Module Kit](http://www.ti.com/tool/cc2531emk). The built-in USB interface should be recognized as an USB<-> Serial Converter Chip and AT-Commands can then be send via an serial terminal connection. The CC2531 should act as a Node in an 6LoWPAN Network connected to different Nodes and to an EDGE-Router to the Internet like shown below.

![6LoWPAN Network](http://processors.wiki.ti.com/images/8/8c/20979_6LowPan_mesh.jpg)

## Prerequisites

You need the following Soft- and Hardware in order to use this project.

###### Software

- [VirtualBox](https://www.virtualbox.org) - An x86/ AMD64 Virtualization Software
- The [Instant Contiki OS Image Version 2.7](https://sourceforge.net/projects/contiki/files/Instant%20Contiki/Instant%20Contiki%202.7/InstantContiki2.7.zip/download) - Used as development base for this project
- [Texas Instruments SmartRF-Flash Programmer](http://www.ti.com/tool/flash-programmer) (**Requires Registration**) - Software used to flash firmware onto the CC2531 chip

###### Hardware

- [Texas Instruments CC2531 USB Evaluation Module Kit](http://www.ti.com/tool/cc2531emk) - The USB Evaluation Kit

- [CC-Debugger](http://www.ti.com/tool/CC-DEBUGGER) - Programmer and Debugger Hardware

## Building Process

[Contiki OS 2.7](http://contiki-os.org) is being used as an embedded operating System running on the CC2531 System-on-Chip. In order to build this project you need to:

1. Download the [Instant Contiki OS Image Version 2.7](https://sourceforge.net/projects/contiki/files/Instant%20Contiki/Instant%20Contiki%202.7/InstantContiki2.7.zip/download)
2. Unpack the Files
3. Mount the Disk Image in VirtualBox or VMWare Player and setup an shared folder for sharing files between Host and Guest Machine
4. Start the Virtual Machine
5. Log-In with with the password user

*You can also Reefer to [here](http://contiki-os.org/start.html) for these steps*

6. Execute `sudo nano /etc/environment` in an Terminal and add these two lines at the end and replace 

   - `<ABSOLUTE_CONTIKI_PATH>` with the absolute path where the contiki folder is located, **without / slash at the end.** Example: `CONTIKI_PATH="/home/user/contiki"`
   - `<ABSOLUTE_SDCC_PATH>` with the absolute path where the sdcc folder is located, **without / slash at the end.** Example: `SDCC_PATH="/usr/local/share/sdcc"`

   ```bash
   CONTIKI_PATH="<ABSOLUTE_CONTIKI_PATH>"
   SDCC_PATH="<ABSOLUTE_SDCC_PATH>"
   ```

7. Logoff and Login again

8. Open up a Terminal and enter 

   ```bash
   git clone https://github.com/BlkPingu/zigPAN
   cd ./zigPAN/src
   make
   ```

   After finishing the `make` command you should have an .hex file in the ./src folder that you can move to your shared folder and then flash onto the CC2531 Chip.

   

## Building the 8051 SDCC Toolchain manually

This guide lists the packages required before you can build/use Contiki's 8051-based ports.

Information on this page has been tested on Ubuntu and on Mac OS X. Things should work on Cygwin but may require some tweaking.

This guide is a clone of the [guide on GitHub](https://github.com/g-oikonomou/contiki-sensinode/wiki/Prepare-your-System guide on GitHub). In cases where you see conflicting information, this page here wins.

### Required Software

Make sure you have the following installed:

* gcc
* flex
* bison
* [Boost C++ Libraries](http://www.boost.org/ ) (package libboost-graph-dev in the ubuntu archive)
* Python
* [srecord](http://srecord.sourceforge.net/)

### OS X specific

* If you want to run border routers on Mac OS X, you will also need [TunTap](http://tuntaposx.sourceforge.net/)
* Do yourself a favour and start by installing [homebrew](http://mxcl.github.com/homebrew/) if you don't have it.
* You should be able to `brew install srecord`. At the time of writing, this command would result in boost getting installed as well so two birds with one stone.
* If you want to build srecord from source, you may need to install [GNU libtool](http://www.gnu.org/software/libtool/). An easy way to do it is via homebrew.

This is what happens if you try to compile srecord with the Apple libtool:

```bash
make
libtool --mode=compile --tag=CXX g++  \
		-g -O2 -I. -c srec_cat/arglex3.cc -o \
		srec_cat/arglex3.lo 
libtool: unknown option character `-' in: --mode=compile
Usage: libtool -static [-] file [...][-filelist listfile[,dirname]] [-arch_only arch][-sacLT]
Usage: libtool -dynamic [-] file [...][-filelist listfile[,dirname]] [-arch_only arch][-o output]
[-install_name name][-compatibility_version #] [-current_version #][-seg1addr 0x#] [-segs_read_only_addr 0x#]
[-segs_read_write_addr 0x#][-seg_addr_table ] [-seg_addr_table_filename <file_system_path>]
[-all_load][-noall_load]
make: *** [srec_cat/arglex3.lo] Error 1
```

Try this:

```bash
libtool -V
Apple Inc. version cctools-822
```

If you install GNU libtool via homebrew, it will be prefixed with a 'g':

```bash
glibtool --version
libtool (GNU libtool) 2.4.2
Written by Gordon Matzigkeit gord@gnu.ai.mit.edu, 1996

Copyright (C) 2011 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

Change srecord's build system to use glibtool instead of libtool and you are sorted.

* Homebrew is also an easy way to install libboost

  ```bash
  brew install boost
  ```

  

### Build your Toolchain (SDCC)

In order to compile contiki, you need a version of the SDCC compiler. Unfortunately, the binary packages don't contain all the libraries we need so you will have to compile SDCC from sources.

Before anything else, make sure you don't have a pre-installed version from the Ubuntu archive!

SDCC supports various device types. You can compile it with support for all of them or only some. The port of interest to us is the mcs51. Disabling all other ports will make the compile considerably faster.

`Recent Tested SDCC revisions: 9092`

* Download a recommended revision from the SDCC svn (replace [rev] with one of the numbers above):

```bash
svn co -r [rev] svn://svn.code.sf.net/p/sdcc/code/trunk/sdcc
```

SDCC revisions between 7102 and 8719 suffer from a [bug](http://sourceforge.net/p/sdcc/bugs/1986/) and can't build banked firmware. Make sure you are not using one of those revisions. If you are getting the error below, this is most probably the cause and you need to rebuild SDCC:

```bash
srec_cat -disable_sequence_warnings border-router.banked-hex -intel -crop 0x18000 0x1FFFF -offset -65536 -o bank1.hex -intel
srec_cat -disable_sequence_warnings border-router.banked-hex -intel -crop 0x28000 0x2FFFF -offset -98304 -o bank2.hex -intel
srec_cat -disable_sequence_warnings border-router.banked-hex -intel -crop 0x38000 0x3FFFF -offset -131072 -o bank3.hex -intel
srec_cat -disable_sequence_warnings border-router.banked-hex -intel -crop 0x48000 0x4FFFF -offset -163840 -o bank4.hex -intel
srec_cat -disable_sequence_warnings border-router.banked-hex -intel -crop 0x00000 0x07FFF -o home.ihx -intel
srec_cat home.ihx -intel bank1.hex -intel bank2.hex -intel bank3.hex -intel bank4.hex -intel -o border-router.hex -intel
srec_cat: bank1.hex: 1: file contains no data
make: *** [border-router.hex] Error 1
rm border-router.flags border-router.banked-hex 
obj_cc2530dk/border-router.app.rel
```

* cd into the extracted directory. This will be called `sdcc`

* Now you need to hack sdcc's build system a bit, in order to get correct library versions.

  - Edit `device/lib/incl.mk`. We need model-huge and model-large libraries. To instruct the build system to build model-huge libraries, find this line:
    `MODELS = small medium large`
    Add `huge`. You may remove `small` and `medium` if you only use SDCC for contiki, but make sure you keep `large`. So your new line may end up looking like this
    `MODELS = small large huge`

  - Edit `device/lib/Makefile.in`. Find this line:
    `TARGETS        += models small-mcs51-stack-auto`
    Replace it with this
    `TARGETS        += models model-mcs51-stack-auto`

* Run this:

  ```bash
  ./configure --disable-gbz80-port --disable-z80-port --disable-ds390-port --disable-ds400-port --disable-pic14-port --disable-pic16-port --disable-hc08-port --disable-r2k-port --disable-z180-port --disable-sdcdb --disable-ucsim
  ```

  - If you don't have root access you will probably want to change the installation directory. You can do that with the `--prefix=dir` option of the `./configure` stage.
  - If you get any errors about missing packages, fix them.

* `make`

* `make install` as root or with sudo

You now have a working compiler and libraries. The SDCC executable might be outside the PATH, depending where you installed it. Try running `sdcc -v` and see if it's in the PATH. If not, add it. If SDCC is in the PATH and you have compiled excluding unused ports, `sdcc -v` will show you something like this:

`SDCC : mcs51 3.4.1 #9092 (Oct 22 2014) (Mac OS X x86_64)`

The list of supported ports appears after the : and before the version number. If you build everything this message will be a lot longer.



## First attempt by using the Sensinode SDCC Banked Tool-Chain and [Free-RTOS](https://www.freertos.org)

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites

What things you need to install the software and how to install them

```
Give examples
```

### Installing

#### Linux Requirements

Requirements:

● gcc, glibc, make, tar, textutils, grep, find

● sdcc version 2.7.0 or later with large-stack-auto library and banking

SDCC package from Sensinode (with banking support). Does not work for applications larger than 64 kb of ROM.

● minicom (or other serial port terminal program)

● rpm for microcontroller tool installation

● doxygen for rebuilding NanoStack references

● a USB port + FTDI USB drivers (part of the standard Linux kernel)



The distribution package names depend on your distribution.

A binary install requires only the serial interface from the above mentioned list and in addition to that it

requires rpm in Fedora Core (or other rpm based) systems.

The installation of the nRouted daemon requires root privileges. It is possible to install the nRouted not as

a system daemon that is started automatically when the system starts but rather as an ordinary program. In

such case the process does not require root privileges but it still requires that the user must have access to

the serial device (e.g. /dev/ttyUSB0).

#### Linux Installation

The PC software CD contains the NanoStack tools packaged for selected Linux distributions. Supported

distributions are Fedora Core 4 and later.

In Fedora Core the tool binaries are installed by issuing the command:

`cd <CD-ROM root>`

`cd toolchains/linux/rpm`

`rpm -Uvh *.rpm`

This installs the SDCC compiler and libraries. Try that SDCC works by typing sdcc and then asx8051 on

the command line. You may need to make sybolic links to sdcc on some systems if the NanoStack makefile

can not find sdcc or asx8051. These are created like:

`su -`

`cd /usr/bin/`

`ln -s sdcc-sdcc sdcc`

`ln -s sdcc-asx8051 asx8051`

To install NanoStack the source package is extracted from the CD to a directory where the user has

permissions to create new files and subdirectories. Then the Makefile should be able to handle the rest. For

example:

Copy the NanoStack directory from the CD-ROM to your working directory.

`cd <working directory>`

`cp -R /<CD-ROM path>/NanoStack/NanoStack-v1.0.3/ .`

`You can now test that NanoStack builds properly like this:`

`cd <working directory>/NanoStack-v1.0.3/Examples/nano_skeleton`

`make`

You should see the build process complete without errors and a nano_skeleton.hex file appear in the same

directory.



A step by step series of examples that tell you have to get a development env running

Say what the step will be

```
Give the example
```

And repeat

```
until finished
```

End with an example of getting some data out of the system or using it for a little demo

## Authors

* **Tobias Kolb**
* **Steven Bradley**

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* https://github.com/g-oikonomou/contiki-sensinode
* https://github.com/mitshell/CC2531

