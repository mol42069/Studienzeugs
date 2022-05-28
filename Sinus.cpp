#include <iostream>
#include <cmath>

class Sin {
public:
	int *SinY;
	int *GivenSinY;
	int width;
	int Angle;
	int GivenSinAngle = 0;
	int UserAmplitute;
	int GivenSinAmplitute;
	int GivenSinAngleSpeed;

	void initSin(int width) {
		int *SinY = new int(width);
		int* GivenSinY = new int(width);
		this->width = width;
		Angle = 0;
		GivenSinAngleSpeed = 0;												// !!!! Has to be set to random
		GivenSinAmplitute = 1;												// !!!! Has to be set to random and not to high or low otherwise it will be out of frame !
	}
	bool SinusRiddle(int SP1_Angle, int SP2_Amplitute){
		if (!SinIsSolved()) {											
			UserAmplitute = SP2_Amplitute;
			calculateSin(SP1_Angle, SP2_Amplitute);
			DrawcurSin();
			return false;
		}
		else {
			return true;
		}
	}
	int getSinValueAt(int x /*starts at 0*/) {
		return(SinY[x]);
	}
private:
	bool SinIsSolved() {
		if (GivenSinAngle == Angle) {
			if (GivenSinAmplitute == UserAmplitute) {
				delete SinY;
				delete GivenSinY;
				return true;
			}
			else {
				return false;
			}
		}
	}
	void DrawcurSin() {
		for (int i = 0; i < width; ++i) {
																		//Draw each Point to Display !!!!
		}
	}
	void calculateSin(double SP1_Angle, double SP2_Amplitute) {
		int x = 0;
		int Angle = 0;
		for (int i = 0; i < width; i++) {
			SinY[i] = SP2_Amplitute*sin(Angle * i + x);
			Angle += SP1_Angle;
			GivenSinY[i] = GivenSinAmplitute * sin(GivenSinAngle * i + x);
			GivenSinAngle += GivenSinAngleSpeed;
		}
		DrawcurSin();
	}
};
