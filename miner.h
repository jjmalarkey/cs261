#ifndef MINER_H
#define MINER_H
#include <string>

class baseMiner {
	static unsigned int botCount; 
	unsigned int id;
	std::string designation;
public:
	void start();
	virtual void detect();
	virtual void collect();
	void stop();
	unsigned int getID();
	std::string getDesignation();
	baseMiner(std::string resource);
	virtual ~baseMiner();
};

class fluidMiner : public baseMiner {
public:
	void collect();
	fluidMiner(std::string resource);
	virtual ~fluidMiner();
};
/*
class solidMiner : public baseMiner {
public:
	void collect();
	solidMiner();
	virtual ~solidMiner();
}
*/
class waterMiner : public fluidMiner {
public:
	void detect();
	waterMiner();
	~waterMiner();
};
/*
class thermalMiner : public fluidMiner {
public:
	void detect();
	thermalMiner();
	~thermalMiner();
}

class grinderMiner : public solidMiner {
public:
	void detect();
	grinderMiner();
	~grinderMiner();
}

class magnetometerMiner : public solidMiner {
public:
	void detect();
	magnetometerMiner();
	~magnetometerMiner();
}

class steamMiner : public solidMiner {
public:
	void detect();
	steamMiner();
	~steamMiner();
}
*/

#endif
