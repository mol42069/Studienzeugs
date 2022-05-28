#pragma once
#include "Sinus.cpp"


namespace SinusCurve{

	class Sin {
	public:
		void initSin(int width);
		bool SinusRiddle(int SP1_Angle, int SP2_Amplitute);
		int getSinValueAt(int x /*starts at 0*/);

	private:
		bool SinIsSolved();
		void DrawcurSin();
		void calculateSin(double SP1_Angle, double SP2_Amplitute);
	};
}
