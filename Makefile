CC=cc
CFLAGS=-Wall -g
LDFLAGS=-lm -lcunit

BUILDDIR = build
SRCS = $(wildcard *.c)
PROGS = $(patsubst %.c,%,$(SRCS))

all: $(PROGS)
%: %.c
	 $(CC) $(CFLAGS) -o $(BUILDDIR)/$@ $< $(LDFLAGS)

clean:
	rm -f $(BUILDDIR)/*