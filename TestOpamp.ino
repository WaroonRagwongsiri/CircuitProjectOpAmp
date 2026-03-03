#include "Opamp.h"

void setup()
{
	Serial.begin(9600);

	init_opamp();
	init_display();
}

void loop()
{
	float v_out  = (analogRead(V_OUT)  / 4095.0f) * 3.3f;
	float v_src1 = (analogRead(V_SRC1) / 4095.0f) * 3.3f;
	float v_src2 = (analogRead(V_SRC2) / 4095.0f) * 3.3f;

	static uint32_t lastPrint = 0;
	uint32_t now = millis();
	if (now - lastPrint >= 200)
	{
		lastPrint = now;
		Serial.printf("v_o = %5.3f | v_1 = %5.3f | v_2 = %5.3f\n", v_out, v_src1, v_src2);
	}

	display_float_3dp_step(v_out);
	delay(5);
}

void init_opamp(void)
{
	pinMode(V_OUT, INPUT);
	pinMode(V_SRC1, INPUT);
	pinMode(V_SRC2, INPUT);
}
