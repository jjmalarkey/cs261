#include "miner.h"
#include <iostream>

using namespace std;

//baseMiner code

unsigned int baseMiner::botCount = 0;

string baseMiner::start() {
	string returnval = "Miner #" + to_string(id) + " (" + designation + ") is starting\n";
	return returnval;
}

string baseMiner::detect() {
	return "";
}

string baseMiner::collect() {
	return "";
}

string baseMiner::stop() {
	string returnval = "Miner #" + to_string(id) + " (" + designation + ") is going to standby\n";
	return returnval;
}

unsigned int baseMiner::getID() {
	return id;
}

string baseMiner::getDesignation() {
	return designation;
}

baseMiner::baseMiner(std::string resource) : designation(resource) {
	id = ++botCount;
}

baseMiner::baseMiner() {}

baseMiner::~baseMiner() {
	botCount--;
}

//fluidMiner code

string fluidMiner::collect() {
	return "Water vacuums and hoses deployed.\nHeater turned on. Waiting for the ice to melt.\nLiquid water moved to collection chamber.\nSurface pump activated.\n";
}

fluidMiner::fluidMiner(string resource) : baseMiner(resource) {}

//solidMiner code

solidMiner::solidMiner(string resource) : baseMiner(resource) {}

string solidMiner::collect() {
	return "Impact hammer positioned.\nImpact hammer activated for 15 seconds.\nDebris scoop activated.\nDebris elevator activated.\nDebris collection complete.\n";
}

//iceMiner code

string iceMiner::detect() {
	return "Initiating heat blast.\nDirectional humidity detector activated.\nIce located.\n";
}

iceMiner::iceMiner(string resource) : fluidMiner(resource) {}

//thermalMiner code

string thermalMiner::detect() {
	return "Releasing oxygen...\nThermal detector activated.\nFlammable reaction detected.\n";
}

thermalMiner::thermalMiner(string resource) : solidMiner(resource) {}

//grinderMiner code

string grinderMiner::detect() {
	return "Sample grinder activated.\n10 um seive applied.\nInfrared laser activated.\nSpectrophotometer activated and results analyzed.\nSilca vein located.\n";
}

grinderMiner::grinderMiner(string resource) : solidMiner(resource) {}

//magnetometerMiner code

string magnetometerMiner::detect() {
	return "Magnetometer activated.\nSearching for magnetic field deviations.\nIron deposits located.\n";
}

magnetometerMiner::magnetometerMiner(string resource) : solidMiner(resource) {}

//steamMiner code

string steamMiner::detect() {
	return "Steam blasting...\nSalinity detector activated.\nConcentration vector of NaCl detected.\n";
}

steamMiner::steamMiner(string resource) : solidMiner(resource) {}

//	from here is mostly constructors that supply the right resource identity

waterMiner::waterMiner() : iceMiner("water") {}

sodiumMiner::sodiumMiner() : steamMiner("sodium") {}

chlorideMiner::chlorideMiner() : steamMiner("chloride") {}

ironMiner::ironMiner() : magnetometerMiner("iron") {}

siliconMiner::siliconMiner() : grinderMiner("silicon") {}

magnesiumMiner::magnesiumMiner() : thermalMiner("magnesium") {}

potassiumMiner::potassiumMiner() : thermalMiner("potassium") {}
