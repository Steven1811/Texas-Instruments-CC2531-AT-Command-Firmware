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

6. Open up a Terminal and enter 

   ```bash
   git clone https://github.com/BlkPingu/zigPAN
   cd ./zigPAN/src
   make
   ```

   

   After finishing the  `make` command you should have an .hex file in the ./src folder that you can move to your shared folder and then flash onto the CC2531 Chip.

   

## Flashing the .hex file on the CC2531

**[TODO]**



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

