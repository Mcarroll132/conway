CC      = gcc
CFLAGS  = -Wall -Wextra -O2
PREFIX ?= $(HOME)/conway-install

OBJS = main.o life.o

all: conway

conway: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c life.h
	$(CC) $(CFLAGS) -c $< -o $@

install: conway
	mkdir -p $(PREFIX)/bin
	cp conway $(PREFIX)/bin/

clean:
	rm -f conway $(OBJS)

.PHONY: all install clean
