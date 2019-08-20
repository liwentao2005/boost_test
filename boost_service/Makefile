# Point to your Boost top level directory
BOOST_ROOT = /usr/include/boost

# Hardcode compiler
CXX := g++

CXXFLAGS := -std=c++11 -I$(BOOST_ROOT)
LDFLAGS := -lboost_thread -lboost_system

src := $(shell ls *.cpp)
objs := $(patsubst %.cpp,%.o,$(src))

all: main

main: $(objs)
	g++ -o $@ $< $(CXXFLAGS) $(LDFLAGS)

clean:
	rm -f main $(src:.cpp=.o)
