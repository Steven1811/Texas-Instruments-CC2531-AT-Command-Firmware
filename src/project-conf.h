/*
 * contiki-conf.h
 *
 *  Created on: 24.06.2018
 *      Author: steven
 */
#define MODELS_CONF_CC2531_USB_STICK 1 //We use the USB Variant of the CC2530
#define AT_DEBUG 1 //Used for debugging the AT Driver
#define IEEE802154_CONF_PANID 0xDEAD //Sets the 16 bit PAN_ID
#define CC2530_RF_CONF_CHANNEL 25 //Sets the RF Channel
#define NETSTACK_CONF_WITH_IPV6 1 //#Set's the Netstack to use the IPv6 driver
#define CC2531_CONF_B2_REBOOTS 1 //Reboot when B2 is pressed
