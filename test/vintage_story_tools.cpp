#include <gtest/gtest.h>
#include "../src/consolelib/vintage_story_tools.hpp"

using namespace consolelib;

TEST(VintageStoryTools, UTIL_FUNCTIONS)
{
	EXPECT_EQ(vintage_story_tools::is_part_percentage(6.4, 8, 80), false);
	EXPECT_EQ(vintage_story_tools::is_part_percentage(7.4, 8, 80), true);

	EXPECT_EQ(vintage_story_tools::is_part_percentage(73.6, 92, 80), true);
}

TEST(VintageStoryTools, BASIC_CALCULATIONS_FOR_500)
{
	vintage_story_tools::InputVectorSimple input;
	input.push_back({"Tin", 8});
	input.push_back({"Copper", 92});
	vintage_story_tools::ResultVector results = vintage_story_tools::calc_unit_dist(input, 500);

	EXPECT_EQ(results.at(0).second, 40);
	EXPECT_EQ(results.at(1).second, 460);
}

TEST(VintageStoryTools, BASIC_CALCULATIONS_FOR_400)
{
	vintage_story_tools::InputVectorSimple input;
	input.push_back({"Tin", 8});
	input.push_back({"Copper", 92});
	vintage_story_tools::ResultVector results = vintage_story_tools::calc_unit_dist(input, 400);
	//vintage_story_tools::round_units_to_int(results);

	EXPECT_EQ(results.at(0).second, 32);
	EXPECT_EQ(results.at(1).second, 368);
}

TEST(VintageStoryTools, BASIC_CALCULATIONS_FOR_400_NORMALIZED)
{
	vintage_story_tools::InputVectorSimple input;
	input.push_back({"Tin", 8});
	input.push_back({"Copper", 92});
	vintage_story_tools::ResultVector results = vintage_story_tools::calc_unit_dist(input, 400);
	vintage_story_tools::normalize_units(results);

	EXPECT_EQ(results.at(0).second, 6.4);
	EXPECT_EQ(results.at(1).second, 73.6);
}

TEST(VintageStoryTools, BASIC_CALCULATIONS_FOR_400_NORMALIZED_INTEGER_UNITS)
{
	vintage_story_tools::InputVectorSimple input;
	input.push_back({"Tin", 8});
	input.push_back({"Copper", 92});
	vintage_story_tools::ResultVector results = vintage_story_tools::calc_unit_dist(input, 400);
	vintage_story_tools::normalize_units(results);
	vintage_story_tools::round_units_to_int(input, results, 80);

	EXPECT_EQ(results.at(0).second, 7);
	EXPECT_EQ(results.at(1).second, 73);
}
