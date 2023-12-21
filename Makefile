EXEChain = pq
OBJS  = main.o chain.o

CXX = g++
CXXFLAGS = -std=c++1y -c -g -O0 -Wall -Wextra -pedantic
LD = g++
LDFLAGS = -std=c++1y -lpthread -lm

all : pq

$(EXEChain) : $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXEChain)

main.o : main.cpp chain.o
	$(CXX) $(CXXFLAGS) main.cpp

chain.o : chain.cpp chain.h
	$(CXX) $(CXXFLAGS) chain.cpp

clean :
	-rm -f *.o $(EXEChain)
