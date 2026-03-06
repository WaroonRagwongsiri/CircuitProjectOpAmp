#ifndef OP_AMP

# include <cstdint>
# include <SevSeg.h>

# define V_OUT 13
# define V_SRC1 14
# define V_SRC2 27

// Segments
# define A 33
# define B 17
# define C 19
# define D 22
# define E 23
# define F 25
# define G 18
# define DP 21

// Digits
# define D1 5
# define D2 16
# define D3 26
# define D4 32

// Button
# define BUTTON1 35
# define BUTTON2 34
# define BUTTON3 39
# define BUTTON4 36

# define NUMBER_MAX 20

// OpAmp
void init_opamp(void);
void init_button(void);
void read_volt(void);
void read_button(void);
void toggle_button(void);

// Display
void init_display(void);
void display_float_3dp_step(float value);
void display_int4_step(int value);

// Debounce
# define DEBOUNCE_MS 50

#endif