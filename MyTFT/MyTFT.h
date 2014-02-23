/*
 * TFT.h
 *
 *  Created on: 7 feb. 2014
 *      Author: svenvandermeij
 */

#ifndef MYTFT_H_
#define MYTFT_H_

#include "Arduino.h"
#include <stdlib.h>
#include <Time.h>

#include "SPI.h"
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

class MyTFT {
protected:
	Adafruit_ILI9341 *tft;
	float last_ambient, last_barrel, last_meat, last_target;
	int last_gasvalve, last_smokevalve, last_smoking_started;
	long last_secondsRemaining;
	bool last_is_meat_selected;
	void init(void);
public:
	MyTFT(uint8_t TFT_CS, uint8_t TFT_DC, uint8_t TFT_MOSI, uint8_t TFT_CLK, uint8_t TFT_RST, uint8_t TFT_MISO);
	MyTFT(Adafruit_ILI9341* t);
	Adafruit_ILI9341* getTFT(void);
	void displayTime(tmElements_t *time);
	void displayTemps(float ambient, float meat, float barrel, float target, bool isMeatSelected);
	void displayValveStatus(int smokeValve, int gasValve);
	void displayTimeRemaining(long secondsRemaining, int smokingStarted);
};

#endif /* MYTFT_H_ */