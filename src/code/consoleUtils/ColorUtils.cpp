//============================================================================
// Name        : Colors
// Author      : Riyufuchi
// Created on  : 20.11.2021
// Last Edit   : 19.12.2023
//============================================================================
#include "../../inc/ColorUtils.h"

namespace ConsoleUtils
{
ColorUtils::ColorUtils()
{
}
ColorUtils::~ColorUtils()
{
}
Color ColorUtils::newColor(short int r, short int g, short int b)
{
	Color color;
	color.red = r;
	color.green = g;
	color.blue = b;
	return color;
}
Color ColorUtils::getColor(ColorPallete color)
{
	switch (color)
	{
		case HAUNTED: return newColor(56, 243, 171);
		case UNIQUE :return newColor(255, 215, 0);
		case STRANGE: return newColor(207, 106, 50);;
		case UNUSUAL: return newColor(134, 80, 172);
		case COLLECTORS: return newColor(170, 0, 0);
		case VALVE_VIOLET: return newColor(165, 15, 121);
		case COMMUNITY: return newColor(112, 176, 74);
		case PINK_AS_HELL: return newColor(255, 105, 180);
		case AUSTRALIUM_GOLD: return newColor(231, 181, 59);
		case No_216_190_216: return newColor(216, 190, 216);
		case SMARAGDINE: return newColor(74,153,118);
		case CONSOLE_ART_UNIX_DEFAULT: return newColor(5, 195, 221);
		case APERTURE_ORANGE: return newColor(255, 157, 0);
		case TERMINAL_FG: return newColor(211, 215, 207);
		default: return newColor(255, 215, 0);
	}
}
} /* namespace LuaController */
