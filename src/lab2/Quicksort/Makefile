CXX=icpx
CXXFLAGS=-Wall -Wextra -O2 -xhost -qopt-report -qopenmp

LDFLAGS=-lm

all: quicksort

quicksort: quicksort.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: clean

clean:
	rm -rf quicksort *.o *opt *yaml heat
