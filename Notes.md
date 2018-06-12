### Contiki get Started:



##### Using Contiki OS for development (We're using version 3.0, since 2.6 doesn't have compatibility for the CC2531 USB drivers and 2.7 has a bug that crashes the controller when utilizing IPv6)

1. Get the [latest Contiki Image](https://sourceforge.net/projects/contiki/files/Instant%20Contiki/)
2. [Get Started](http://contiki-os.org/start.html)
3. [Contiki CC2531 example](https://github.com/contiki-os/contiki/blob/master/examples/cc2530dk/cc2531-usb-demo/cc2531-usb-demo.c)

#### Resources

1. [How to flash with Contiki-2.7](https://stackoverflow.com/questions/20277203/contiki-and-cc2531-usb-dongle)
2. [CC2531 Dongle and Contiki](https://e2e.ti.com/support/wireless_connectivity/zigbee_6lowpan_802-15-4_mac/f/158/t/214272?CC2531-USB-Dongle-and-Contiki)
3. [Contiki Documentation](http://contiki.sourceforge.net/docs/2.6/index.html)
4. [Registerdefinitions for CC253x used on Contiki](http://contiki.sourceforge.net/docs/2.6/a00693_source.html)
5. [CC253x User's Guide](http://www.ti.com/lit/ug/swru191f/swru191f.pdf)
6. [How to build the 8051 SDCC Toolchain manually](https://github.com/contiki-os/contiki/wiki/8051-Requirements)
7. [Contiki Network Stack](https://anrg.usc.edu/contiki/index.php/Network_Stack)
8. [Contiki RPL UDP](http://anrg.usc.edu/contiki/index.php/RPL_UDP)

#### Important files to look into (Contiki OS 3.0)

**Main configuration**

- core/contiki-default-conf.h - Default configuration that get's loaded in Contiki
- platform/cc2530dk/contiki-conf.h - Platform specific configuration that get's loaded in Contiki

**Networking**

- core/net/netstack.h - The networking stack interface of Contiki
- core/net/dev/radio.h - Low-level driver for the platform
- core/net/ip/uip.h - Basic IP communication in Contiki

**USB Communication**

- platform/cc2530dk/usb-serial.h - The serial USB Driver for the platform

**Platform-specific**

- platform/cc2530dk/contiki-main.c - Initialization routines for the platform (Setting up drivers, etc.)