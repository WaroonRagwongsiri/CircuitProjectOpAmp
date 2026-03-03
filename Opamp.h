#ifndef OP_AMP

# include <cstdint>
# include <SevSeg.h>

# define V_OUT 13
# define V_SRC1 14
# define V_SRC2 27

// Segments
# define A 16
# define B 17
# define C 5
# define D 18
# define E 19
# define F 21
# define G 22
# define DP 23

// Digits
# define D1 26
# define D2 25
# define D3 33
# define D4 32

// Button
# define BUTTON1 35
# define BUTTON2 34
# define BUTTON3 39
# define BUTTON4 36

// OpAmp
void init_opamp(void);
void init_button(void);
void read_volt(void);
void read_button(void);

// Display
void init_display(void);
void display_float_3dp_step(float value);
void display_int4_step(int value);

// Debounce
# define DEBOUNCE_MS 50

#endif