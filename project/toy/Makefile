# makefile configuration
COMMON_OBJECTS 	=
CPU		= msp430g2553
CFLAGS		= -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (internal make rules)
CC		= msp430-elf-gcc
AS		= msp439-elf-as

all: toy.elf

#additional rules for files
toy.elf: ${COMMON_OBJECTS} p1_interrupt_handler.o led.o switches.o buzzer.o toyMain.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: toy.elf
	msp430loader.sh toy.elf

clean:
	rm -f *.o *.elf

buzzer.o: buzzer.c buzzer.h
toyMain.c: buzzer.h
