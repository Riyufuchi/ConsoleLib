//============================================================================
// Name        : Colors
// Author      : Riyufuchi
// Created on  : 20.11.2021
// Last Edit   : 23.11.2023
//============================================================================

#ifndef SRC_INC_COLORS_H_
#define SRC_INC_COLORS_H_

namespace ConsoleUtils
{
class Colors
{
public:
	enum ColorPallete
	{
		HAUNTED,
		UNIQUE,
		STRANGE,
		UNUSUAL,
		COLLECTORS,
		VALVE_VIOLET,
		COMMUNITY,
		PINK_AS_HELL,
		AUSTRALIUM_GOLD,
		No_216_190_216,
		SMARAGDINE,
		CONSOLE_ART_UNIX_DEFAULT,
		COLOR_COUNT  // This can be used to determine the size of the enum
	};
	typedef struct Color // This way, there is no need to cast, because uint8_t would be treated as char not numerical value
	{
		short int red;
		short int blue;
		short int green;
	} tColor;
	static constexpr const char* colorPaletteNames[] =
	{
		"HAUNTED",
		"UNIQUE",
		"STRANGE",
		"UNUSUAL",
		"COLLECTORS",
		"VALVE_VIOLET",
		"COMMUNITY",
		"PINK_AS_HELL",
		"AUSTRALIUM_GOLD",
		"No_216_190_216",
		"SMARAGDINE",
		"CONSOLE_ART_UNIX_DEFAULT"
	};
	Colors();
	virtual ~Colors();
	static Color getColor(ColorPallete color);
	static Color newColor(short int r, short int g, short int b);
};
} /* namespace LuaController */
#endif /* SRC_INC_COLORS_H_ */
