#ifndef MINERMGR_H
#define MINERMGR_H
#endif
#include <iostream>
#include <vector>
#include <string>
#ifndef MINER_H
#include "miner.h"
#endif

class minermgr {
	std::vector<baseMiner *> bots;
	unsigned int botListAllocation;
public:
	void addMiner(unsigned int minerNumber, std::string resource);
	void runMiners();
	minermgr();
	~minermgr();
};
