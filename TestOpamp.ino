#include "Opamp.h"

void setup()
{
	Serial.begin(9600);

	init_opamp();
	init_display();
	init_button();
}

static int raw[3] = {};
static float volt[3] = {};

static int mode = 0;
static int current = 0;

void loop()
{
	// read_button();
	// read_volt();
	// if (mode == 0)
	// 	display_int4_step(raw[current]);
	// else if (mode == 1)
	// 	display_float_3dp_step(volt[current]);
	display_float_3dp_step(2.761);
}

void init_opamp(void)
{
	pinMode(V_OUT, INPUT);
	pinMode(V_SRC1, INPUT);
	pinMode(V_SRC2, INPUT);
}

void init_button(void)
{
	pinMode(BUTTON1, INPUT);
	pinMode(BUTTON2, INPUT);
	pinMode(BUTTON3, INPUT);
	pinMode(BUTTON4, INPUT);
}

void read_volt(void)
{
	raw[0] = analogRead(V_OUT);
	raw[1] = analogRead(V_SRC1);
	raw[2] = analogRead(V_SRC2);


	volt[0] = (raw[0] / 4095.0f) * 3.3f;
	volt[1] = (raw[1] / 4095.0f) * 3.3f;
	volt[2] = (raw[2] / 4095.0f) * 3.3f;
}

void read_button(void)
{
	static uint32_t lastDebounceTime[4] = {0};
	static uint8_t  lastState[4] = {HIGH, HIGH, HIGH, HIGH};

	uint8_t pins[4] = {BUTTON1, BUTTON2, BUTTON3, BUTTON4};
	uint32_t now = millis();

	for (int i = 0; i < 4; i++)
	{
		uint8_t reading = digitalRead(pins[i]);

		if (reading != lastState[i])
		{
			lastDebounceTime[i] = now;
			lastState[i] = reading;
		}

		if ((now - lastDebounceTime[i]) > DEBOUNCE_MS)
		{
			if (reading == LOW)
			{
				switch (i)
				{
					case 0: current = 0; break;
					case 1: current = 1; break;
					case 2: current = 2; break;
					case 3: mode ^= 1;  break;
				}
			}
		}
	}
}
