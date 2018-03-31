/*
 * Leds.cpp
 *
 *  Created on: 30.03.2018
 *      Author: m
 */

#include <Leds.h>

Leds::Leds() {
	//https://www.sunduino.pl/stm32-porty-gpio-dla-opornych-1/
	//http://hertaville.com/stm32f0-gpio-tutorial-part-1.html

	GPIO_InitTypeDef GPIO_InitStruct;
        // ta struktura u³atwia nam inicjowanie GPIO oraz ustawienia
        // pinów jako In / out czy w³aczenie pullupów

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
        // odmiennie ni¿ w AVR tu ka¿de praktycznie urz¹dzenie perferyjne
        // wymaga w³¹czenia taktowania i tym sposobem w³¹czamy obwody
        // RCC dla GPIO


        // Tu poni¿ej mamy blok instrukcji w którym mamy wszystkie
        // w³aœciwoœci naszych obwodów GPIO.
        // Zatem ustalamy co potrzebujemy i gdzie oraz wywo³ujemy
        // funkcjê init, która  ustali ustawione przez nas bity w
        // odpowiednich rejestrach

        // W przypadku naszego STM32F4 Discovery diody LED, które
        // s¹ na pok³adzie p³ytki s¹ pod³¹czone
        // do pinów PD12 , PD15  ....
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_15 | GPIO_Pin_14 | GPIO_Pin_13 | GPIO_Pin_12; // Chcemy skonfigurowaæ wszystkie piny z diodami
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT; // Wszystkie w/w piny jako wyjœcia
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz; 	// GPIO ma pracowaæ z zegarem 50Mhz - co przek¹³da siê na szybkoœæ zmian
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP; 	// Piny bêda typu Push/pull
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL; 	// Tutaj decydujemy o w³aczeniu PullUP lub PulDown - my dajemy na nieaktywne
	GPIO_Init(GPIOD, &GPIO_InitStruct);

}

Leds::~Leds() {
	// TODO Auto-generated destructor stub
}

void Leds::SetRedLed() {
	//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
	GPIOD->BSRRL = (1<<LED_RED);
}

void Leds::ResetRedLed() {
	//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
	GPIOD->BSRRH = (1<<LED_RED);
}

void Leds::ToggleRedLed() {
	//HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
	GPIOD->ODR ^= (1<<LED_RED);
}

void Leds::SetBlueLed() {
	//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
	GPIOD->BSRRL = (1<<LED_BLUE);
}

void Leds::ResetBlueLed() {
	//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
	GPIOD->BSRRH = (1<<LED_BLUE);
}

void Leds::ToggleBlueLed() {
	//HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_15);
	GPIOD->ODR ^= (1<<LED_BLUE);
}

void Leds::SetGreenLed() {
	//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
	GPIOD->BSRRL = (1<<LED_GREEN);
}

void Leds::ResetGreenLed() {
	//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
	GPIOD->BSRRH = (1<<LED_GREEN);
}

void Leds::ToggleGreenLed() {
	//HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
	GPIOD->ODR ^= (1<<LED_GREEN);
}

void Leds::SetOrangeLed() {
	//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
	GPIOD->BSRRL = (1<<LED_ORANGE);
}

void Leds::ResetOrangeLed() {
	//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
	GPIOD->BSRRH = (1<<LED_ORANGE);
}

void Leds::ToggleOrangeLed() {
	//HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_13);
	GPIOD->ODR ^= (1<<LED_ORANGE);
}


