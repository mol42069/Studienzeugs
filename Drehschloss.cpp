#include <cstdint>

class Drehschloss {

public:

	int curPos;
	int x = 3;									//ammount of right answeres required
	int curSolved;
	int *GivenPositions;
	int *Positions;
	bool solved;
	int oneturn = 40;							//Wieviel eine umdrehung vom RE ist.
	void REclicked() {							// entweder den RE klicken oder ein Button klick! wird bei interupt aufgerufen
		if (curPos != GivenPositions[curSolved]) {
			return;
		}
		else if (curPos == GivenPositions[curSolved]) {	
			curSolved++;
			if (curSolved == x) {
				delete Positions;
				delete GivenPositions;
				Solved();
				return;
			}
			else {
				return;
			}
		}		
	}
	void PlayerSearching(int REE) {
		if (REE > oneturn) {
			REE = REE - oneturn;
		}
		else if (REE < 0) {
			REE = REE + oneturn;
		}
		curPos = REE;
		if (curPos != GivenPositions[curSolved]) {				//make normal sound <- to be implemented
			// audio Ausgabe -> Wrong Sound
		}else if(curPos == GivenPositions[curSolved]){			//make kinda obvious sound <- to be implemented
			// audio Ausgabe -> Right Sound
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
