#ifndef OP_AMP

# include <cstdint>
# include <SevSeg.h>

# define V_OUT 14
# define V_SRC1 26
# define V_SRC2 33

// Segments
# define A 13
# define B 16
# define C 17
# define D 18
# define E 19
# define F 21
# define G 22
# define DP 23

// Digits
# define D1 25
# define D2 27
# define D3 32
# define D4 15

# define B1 25
# define B2 27
# define B3 32
# define B4 15

// OpAmp
void init_opamp(void);

// Display
void init_display(void);
void display_float_3dp_step(float value);
void display_int4_step(int value);

#endif