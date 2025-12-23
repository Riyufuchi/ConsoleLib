//============================================================================
// Name        : ColorUtils
// Author      : Riyufuchi
// Created on  : Nov 20, 2021
// Last Edit   : Dec 23, 2025
//============================================================================
#include "../consolelib/tools/color_tools.h"

namespace consolelib::color_tools
{

Color obtainColor(ColorPallete color)
{
	switch (color)
	{
	case HAUNTED: return Color{56, 243, 171};
	case UNIQUE :return Color{255, 215, 0};
	case STRANGE: return Color{207, 106, 50};
	case UNUSUAL: return Color{134, 80, 172};
	case COLLECTORS: return Color{170, 0, 0};
	case VALVE_VIOLET: return Color{165, 15, 121};
	case COMMUNITY: return Color{112, 176, 74};
	case PINK_AS_HELL: return Color{255, 105, 180};
	case AUSTRALIUM_GOLD: return Color{231, 181, 59};
	case No_216_190_216: return Color{216, 190, 216};
	case SMARAGDINE: return Color{74,153,118};
	case CONSOLE_ART_UNIX_DEFAULT: return Color{5, 195, 221};
	case APERTURE_ORANGE: return Color{255, 157, 0};
	case AMBER: return Color{255, 191, 0};
	case TERMINAL_FG: return Color{211, 215, 207};
	default: return Color{5, 195, 221};
	}
}

Color getColor(ColorPallete color)
{
	return obtainColor(color);
}

}
