GXX = g++
GXXFLAGS = -Wall -g -std=c++11

test: test.cpp miner.o
	$(GXX) $(GXXFLAGS) -o test miner.o test.cpp

miner.o: miner.cpp miner.h
	$(GXX) $(GXXFLAGS) -c miner.cpp miner.h

clean:
	rm *.o *.gch
