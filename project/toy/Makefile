# makefile configuration
COMMON_OBJECTS 	=
CPU		= msp430g2553
CFLAGS		= -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (internal make rules)
CC		= msp430-elf-gcc
AS		= msp439-elf-as

all: button.elf

#additional rules for files
button.elf: ${COMMON_OBJECTS} p1_interrupt_handler.o song.o led.o switches.o buzzer.o toyMain.o wdInterruptHandler.o stateMachines.o lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: button.elf
	msp430loader.sh button.elf

clean:
	rm -f *.o *.elf
led.o: led.c led.h
song.o: song.h 
buzzer.o: buzzer.c buzzer.h
toyMain.o: buzzer.h
wdInterruptHandler.o: stateMachines.h
stateMachines.o: led.h stateMachines.h song.h
