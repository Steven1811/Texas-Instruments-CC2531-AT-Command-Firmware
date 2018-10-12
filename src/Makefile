CONTIKI =${CONTIKI_PATH}
CONTIKI_PROJECT = cc2531-6lowpan-at-terminal
PROJECTDIRS += at at/executors
PROJECT_SOURCEFILES += at.c help.c reset.c test.c rssi.c txpwr.c ch.c pid.c send.c locip.c listen.c led.c
DEFINES+=	PROJECT_CONF_H=\"project-conf.h\"
all: $(CONTIKI_PROJECT)



include $(CONTIKI)/Makefile.include
