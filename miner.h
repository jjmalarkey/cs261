#ifndef MINER_H
#define MINER_H
#include <string>

class baseMiner {
	static unsigned int botCount; 
	unsigned int id;
	std::string designation;
protected:
	unsigned int getID();
	std::string getDesignation();
	baseMiner(std::string resource);
	baseMiner();
public:
	virtual std::string detect();
	virtual std::string collect();
	virtual ~baseMiner();
	std::string stop();
	std::string start();
};
// collection types
class fluidMiner : public baseMiner {
	//virtual std::string detect();
protected:
	std::string collect();
	fluidMiner(std::string resource);
};

class solidMiner : public baseMiner {
protected:
	std::string collect();
	solidMiner(std::string resource);
};
// detection types
class iceMiner : public fluidMiner {
protected:
	std::string detect();
	iceMiner(std::string resource);
};

class thermalMiner : public solidMiner {
protected:
	std::string detect();
	thermalMiner(std::string resource);
};

class grinderMiner : public solidMiner {
protected:
	std::string detect();
	grinderMiner(std::string resource);
};

class magnetometerMiner : public solidMiner {
protected:
	std::string detect();
	magnetometerMiner(std::string resource);
};

class steamMiner : public solidMiner {
protected:
	std::string detect();
	steamMiner(std::string resource);
};

//resource type
//the intent with keeping all parent classes protected is to ensure that instances of parent objects aren't created

class waterMiner : public iceMiner {
public:
	waterMiner();
};

class sodiumMiner : public steamMiner {
public:
	sodiumMiner();
};

class chlorideMiner : public steamMiner {
public:
	chlorideMiner();
};

class ironMiner : public magnetometerMiner {
public:
	ironMiner();
};

class siliconMiner : public grinderMiner {
public:
	siliconMiner();
};

class magnesiumMiner : public thermalMiner {
public:
	magnesiumMiner();
};

class potassiumMiner : public thermalMiner {
public:
	potassiumMiner();
};

#endif
