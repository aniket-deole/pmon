CPP=g++
CFLAGS=-g -rdynamic -O0 -Wall `pkg-config sigc++-2.0 gtk+-3.0 gtkmm-3.0 gdkmm-3.0 --cflags` -Iinclude/

TGT=pmon
OBJS= main.o pmon.o utils.o windowbody.o maintoolbar.o

all : ${OBJS}
		${CPP} ${CFLAGS} -o ${TGT} ${OBJS} `pkg-config sigc++-2.0 gtk+-3.0 gtkmm-3.0 --libs` -Iinclude/

%.o : %.cc
	${CPP} ${CFLAGS} -Iinclude/ -c $<

.PHONY: clean
clean:
	rm -rf *.o pmon

test: all
	./pmon

install: all
	cp pmon /usr/bin/pmon

debug: all
	gdb --tui ./pmon

