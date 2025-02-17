#pragma once

typedef enum _eButton
{
	eb_None,
	eb_Left,
	eb_Right,
	eb_Up,
	eb_Down
} MyButton, *pMyButton;

typedef enum _enColors
{
	CL_BLACK = 0,
	CL_BLUE = 1,
	CL_GREEN = 2,
	CL_AQUA = 3,
	CL_RED = 4,
	CL_PURPLE = 5,
	CL_YELLOW = 6,
	CL_WHITE = 7,
	CL_GRAY = 8,
	CL_LIGHT_BLUE = 9,
	CL_LIGHT_GREEN = 10,
	CL_LIGHT_AQUA = 11,
	CL_LIGHT_RED = 12,
	CL_LIGHT_PURPLE = 13,
	CL_LIGHT_YELLOW = 14,
	CL_LIGHT_WHITE = 15
} MyColors, *pMyColors;

typedef enum _eNameShapes
{
	NONE,
	TRIANGLE,
	RECTANGLE,
	ELLIPSE,
	LINE
} nameshape, *pnameshape;

//typedef enum enModel
//{
//	mod_n_An_Y, mod_n_An, mod_n_Y, mod_An_Y, mod_X, mod_Y
//};

typedef enum _enEncModel
{
	c_mode_Caesar,
	c_mode_CaesarDynamic,
	c_mode_Shift,
	c_mode_Shift_Left,
	c_mode_Shift_Right
} encmode, *pencmode;

typedef enum _action
{
	DEFAULT,
	act_MAZE,
	act_MAZEPATH,
	act_MAZEEXIT,
	act_RECURSION,
	act_CLASSES,
	act_UNIT,
	act_BREAK

} MyAction, *pMyAction;

#define UChar unsigned char