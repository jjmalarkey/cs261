#include "miner.h"

int main() {
	/*
	fluidMiner bot2("potassium");
	baseMiner bot3("iron");
	baseMiner *ptr2 = &bot2;
	baseMiner *ptr3 = &bot3;
	ptr2->stop();
	ptr3->start();
	*/
	waterMiner bot1;
	baseMiner *ptr = &bot1;
	ptr->start();
}
