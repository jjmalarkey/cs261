GXX = g++
GXXFLAGS = -Wall -g -std=c++11

#test: test.cpp miner.o
#	$(GXX) $(GXXFLAGS) -o test miner.o test.cpp

runminers: miner.o minermgr.o runminers.cpp
	$(GXX) $(GXXFLAGS) -o runminers miner.o minermgr.o runminers.cpp

minermgr.o: minermgr.cpp minermgr.h miner.h
	$(GXX) $(GXXFLAGS) -c minermgr.cpp minermgr.h miner.h

miner.o: miner.cpp miner.h
	$(GXX) $(GXXFLAGS) -c miner.cpp miner.h

clean:
	rm *.o *.gch
