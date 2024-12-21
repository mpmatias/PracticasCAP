CC=icx
CFLAGS=-Wall -Wextra-O2 -xhost -qopt-report -qopenmp

LDFLAGS=-lm

all: heat

heat: heat.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: clean

clean:
	rm -rf *.o *opt *yaml heat
