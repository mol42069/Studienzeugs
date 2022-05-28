#include <cstdint>

class Drehschloss {

public:

	int curPos;
	int x = 3;
	int curSolved;
	int *GivenPositions;
	int *Positions;
	bool solved;
	// Variables and stuff to be implemented from STM
	bool REclicked() {		// entweder den RE klicken oder ein Button klick! zum Eingabe confirmen
		return true;		// durch einen interupt
	}
	void PlayerSearching(int REE) {
		curPos = REE;
		if (curPos != GivenPositions[curSolved]) {				//make normal sound <- to be implemented
			if (REclicked() == true) {
				wrong();
			}	
		}else if(curPos == GivenPositions[curSolved]){			//make kinda obvious sound <- to be implemented
			
			if (REclicked() == true) {
				curSolved++;
				if (curSolved == x-1) {
					solved = true;
					Solved();
				}
				else {
					Positions[curSolved] = curPos;
				}
			}
		}
	}
	void init() {
		curPos = 0;
		int *GivenPositions = new int(x);					// new int(x <- wieviele Positionen gefunden werden sollen
		curSolved = 0;
		solved = false;
	}
	void Solved(void) {

		// LED anmachen um zu zeigen das dass Rätsel gelöst ist!
	
	}
	void wrong(void) {

		// do stuff if wrong

	}

};
