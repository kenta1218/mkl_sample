CXX = icpx
CXXFLAGS = -Wall
CXXFLAGS += -I$(MKLROOT)/include
CXXFLAGS += -DMKL
LDFLAGS = -L$(MKLROOT)/lib
LDFLAGS += -qmkl=sequential
LDFLAGS += -pg

all: a.out

a.out: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp $(LDFLAGS)

clean:
	rm -f a.out

-include makefile.local
