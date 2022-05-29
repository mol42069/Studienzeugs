#pragma once

#include "Drehschloss.cpp"

namespace REER {
	class Drehschloss {
	public:
		void REclicked();
		void PlayerSearching(int REE);
		void init();
		void Solved(void);
		void wrong(void);
	};
}
