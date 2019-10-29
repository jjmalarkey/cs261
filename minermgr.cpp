#ifndef MINERMGR_H
#include "minermgr.h"
#endif

using namespace std;

minermgr::minermgr() {
//allocate minimum expected size (10)	
//set botListSize
//print initialization
	bots.reserve(10);
	botListAllocation = 10;
	cout << "== Boston Station Miner Manager ==" << endl << endl << "Authenticating with Van Halen facilities..." << endl <<
		"Connected and registered." << endl;
	//maybe the connection dialogue should happen at minermgr.run()
}

minermgr::~minermgr() {
//step through and delete entries, then clear vector
	for(vector<baseMiner *>::iterator vit = bots.begin(); vit != bots.end(); vit++) {
		delete *vit;
	}
	bots.clear();
}

void minermgr::addMiner(unsigned int minerNumber, string resource) {
//reservations should help, but will test with and without
	if(minerNumber > botListAllocation) {
		botListAllocation *= 10;
		bots.reserve(botListAllocation);
	}
	baseMiner * newBot;
	if(resource == "water") {
		newBot = new waterMiner;
	}
	else if(resource == "sodium") {
		newBot = new sodiumMiner;
	}
	else if(resource == "iron") {
		newBot = new ironMiner;
	}
	else if(resource == "potassium") {
		newBot = new potassiumMiner;
	}
	else if(resource == "chloride") {
		newBot = new chlorideMiner;
	}
	else if(resource == "magnesium") {
		newBot = new magnesiumMiner;
	}
	else if(resource == "silicon") {
		newBot = new siliconMiner;
	}
	else {
		cout << "Error: " << resource << " not found on miner type list" << endl;
	}
	bots.push_back(newBot);
	return;
}

void runMiner(baseMiner * bot) {
	cout << "=======" << endl << "== Command: start" << endl;
	cout << bot->start();
	cout << "== Command: detect" << endl;
	cout << bot->detect();
	cout << "== Command: collect" << endl;
	cout << bot->collect();
	cout << "== Command: stop" << endl;
	cout << bot->stop();
}

void minermgr::runMiners() {
	for(vector<baseMiner *>::iterator vit = bots.begin(); vit != bots.end(); vit++) {
		runMiner(*vit);
	}
	return;
}
