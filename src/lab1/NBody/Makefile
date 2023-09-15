NAME=nbody

CC=icx

CFLAGS=-O2 -g -I. -xHost

DEPS = gtime.h memory.h nbody.h nbody_routines.h

OBJ = gtime.o memory.o nbody.o nbody_routines.o

LIB = -lm

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIB)


clean: 
	rm -f *.o *.optrpt $(NAME)
