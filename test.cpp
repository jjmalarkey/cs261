#include "miner.h"

int main() {
	waterMiner bot1();
	fluidMiner bot2("potassium");
	baseMiner bot3("iron");
	fluidMiner *tmpPtr = &bot1;
	baseMiner *ptr1 = tmpPtr;
	baseMiner *ptr2 = &bot2;
	baseMiner *ptr3 = &bot3;
	ptr1->start();
	ptr2->stop();
	ptr3->start();
}
