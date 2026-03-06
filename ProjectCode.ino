#include "Opamp.h"

void setup()
{
	// Serial.begin(9600);

	init_opamp();
	init_display();
	init_button();
}

static int raw[3] = {};
static float volt[3] = {};
static int clamped[3] = {};

static int mode = 0;
static int current = 0;

void loop()
{
	refresh_display();

	static unsigned long lastUpdate = 0;
	unsigned long now = millis();

	if (now - lastUpdate >= 5)
	{
		lastUpdate = now;

		read_button();
		read_volt();

		if (mode == 0)
			display_int4_step(clamped[current]);
		else
			display_float_3dp_step(volt[current]);
	}
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

	clamped[0] = map(raw[0], 0, 4095, 0, NUMBER_MAX);
	clamped[1] = map(raw[1], 0, 4095, 0, NUMBER_MAX);
	clamped[2] = map(raw[2], 0, 4095, 0, NUMBER_MAX);
}

void read_button(void)
{
	if (digitalRead(BUTTON1) == HIGH)
		current = 0;
	if (digitalRead(BUTTON2) == HIGH)
		current = 1;
	if (digitalRead(BUTTON3) == HIGH)
		current = 2;
	toggle_button();
}

void toggle_button(void)
{
	static unsigned long last_press_time = 0;

	if (digitalRead(BUTTON4) == HIGH)
	{
		unsigned long now = millis();
		if (now - last_press_time > DEBOUNCE_MS)
		{
			mode ^= 1;
			last_press_time = now;
		}
	}
}
