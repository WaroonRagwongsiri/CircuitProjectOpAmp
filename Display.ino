#include "Opamp.h"

static SevSeg sevseg;

void init_display(void)
{
	byte numDigits = 4;
	byte digitPins[] = {D4, D3, D2, D1};
	byte segmentPins[] = {A, B, C, D, E, F, G, DP};

	bool resistorsOnSegments = false;
	byte hardwareConfig = COMMON_CATHODE;

	sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
	sevseg.setBrightness(90);
}

void display_float_3dp_step(float value)
{
	if (value < 0.0f) value = 0.0f;
	if (value > 3.3f) value = 3.3f;

	sevseg.setNumberF(value, 3);
	sevseg.refreshDisplay();
}

void display_int4_step(int value)
{
	if (value < 0) value = 0;
	if (value > 9999) value = 9999;

	sevseg.setNumber(value);
	sevseg.refreshDisplay();
}
