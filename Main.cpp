#include "Sinus.h"
#include "Drehschloss.h"

Sin sinus;
Drehschloss RE;
bool isSinInit;
bool isSinSolved;
bool isDrehSInit;
bool isDrehSSolved;
bool isNeopInit;
bool isNeopSolved;
volatile uint32_t tim1_cnt = 0, direction;
int DisplWidth = 160;			//Actual width of Display!!!
int curRiddle;

void Sinuss() {

	int PotentioRaw = 0;
	int PotentioRaw2 = 0;

	//HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET);
	//HAL_ADC_Start(&hadc1);
	//HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
	//PotentioRaw = (int)HAL_ADC_GetValue(&hadc1);
	//HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
	//HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET);
	//HAL_ADC_Start(&hadc1);
	//HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
	//PotentioRaw2 = (int)HAL_ADC_GetValue(&hadc1);
	//HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);

	if (isSinInit) {
		isSinSolved = sinus.SinusRiddle(PotentioRaw,PotentioRaw2);
		return;
	}
	else {
		sinus.initSin(DisplWidth);
		isSinInit = true;
		isSinSolved = sinus.SinusRiddle(PotentioRaw, PotentioRaw2);
		return;
	}
}
void DSPoti() {
	if(!isDrehSInit){
		//tim1_cnt = htim1.Instance->CNT;
		//direction = !(__HAL_TIM_IS_TIM_COUNTING_DOWN(&htim1));
		RE.PlayerSearching(tim1_cnt);
	}
	else {
		RE.init();
		//tim1_cnt = htim1.Instance->CNT;
		//direction = !(__HAL_TIM_IS_TIM_COUNTING_DOWN(&htim1));
		RE.PlayerSearching(tim1_cnt);
	}
						
}
void Neopixl() {

	if (isNeopInit) {
		//isNeopSolved = *** <- Neopixel function aufrufen
		return;
	}
	else {
		//Neop Init aufrufen
		isNeopInit = true;

		//isNeopSolved = *** <- Neopixel function aufrufen
		return;
	}
}
int main(void) {
	isSinInit = false;
	isSinSolved = false;
	curRiddle = 0;
	isDrehSInit = false;
	isDrehSSolved = false;
	isNeopInit = false;
	isNeopSolved = false;
	while (true) {

		//curRiddle = GyroOut      <--- to be implemented !!

		switch (curRiddle)
		{
		case 0:
			Sinuss();
			break;
		case 1:
			DSPoti();
			break;
		case 2:
			Neopixl();
			break;
		case 3:

			break;
		case 4:

			break;
		case 5:

			break;
		default:
			break;
		}
		//HAL_Delay(10)
	}
}
