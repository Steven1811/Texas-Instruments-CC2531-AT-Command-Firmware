CONTIKI_PROJECT = cc2531-6lowpan-at-terminal
PROJECTDIRS += at at/executors
PROJECT_SOURCEFILES += at.c help.c reset.c test.c rssi.c txpwr.c
DEFINES+=	MODELS_CONF_CC2531_USB_STICK=1\
			AT_DEBUG\ #Used for debugging the AT Driver
			IEEE802154_CONF_PANID=0xDEAD\ #Set's the 16 bit PAN_ID
			CC2530_RF_CONF_CHANNEL=25\ #Set's the RF Channel
			NETSTACK_CONF_WITH_IPV6=1\ #Set's the Netstack to use the IPv6 driver
			CC2531_CONF_B2_REBOOTS=1 #Reboot when B2 is pressed
all: $(CONTIKI_PROJECT)

CONTIKI =${CONTIKI_PATH}

include $(CONTIKI)/Makefile.include
