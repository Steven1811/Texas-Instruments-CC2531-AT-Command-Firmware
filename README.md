# zigPAN

WPAN implementation for TI CC2531 ZigBee Module USB



## Getting Started

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

## Running the tests

Explain how to run the automated tests for this system

### Break down into end to end tests

Explain what these tests test and why

```
Give an example
```

### And coding style tests

Explain what these tests test and why

```
Give an example
```

## Deployment

Add additional notes about how to deploy this on a live system

## Built With

* [Dropwizard](http://www.dropwizard.io/1.0.2/docs/) - The web framework used
* [Maven](https://maven.apache.org/) - Dependency Management
* [ROME](https://rometools.github.io/rome/) - Used to generate RSS Feeds

## Contributing

Please read [CONTRIBUTING.md](https://gist.github.com/PurpleBooth/b24679402957c63ec426) for details on our code of conduct, and the process for submitting pull requests to us.

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/your/project/tags). 

## Authors

* **Billie Thompson** - *Initial work* - [PurpleBooth](https://github.com/PurpleBooth)

See also the list of [contributors](https://github.com/your/project/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* https://github.com/g-oikonomou/contiki-sensinode
* https://github.com/mitshell/CC2531

