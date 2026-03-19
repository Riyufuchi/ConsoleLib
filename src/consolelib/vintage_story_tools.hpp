//==============================================================================
// Author     : riyufuchi
// Created on : 2026-03-16
// Last edit  : 2026-03-16
// Copyright  : Copyright (c) 2026, riyufuchi
//==============================================================================
#ifndef VINTAGE_STORY_TOOLS_HPP
#define VINTAGE_STORY_TOOLS_HPP

#include <vector>
#include <string>
#include <cmath>

namespace consolelib::vintage_story_tools
{

using ResultVector = std::vector<std::pair<std::string, double>>;
//using InputVector = std::vector<std::tuple<std::string, double, double>>;
using InputVectorSimple = std::vector<std::pair<std::string, double>>;

inline double calc_unit_percentage(double part, int product_comp_sum_units)
{
	return (product_comp_sum_units / 100.0) * part;
}
inline ResultVector calc_unit_dist(const InputVectorSimple& components_and_percentages, int product_comp_sum_units)
{
	ResultVector results;

	for (const auto& item : components_and_percentages)
	{
		results.push_back({item.first, calc_unit_percentage(item.second, product_comp_sum_units)});
	}

	return results;
}
inline bool is_part_correct_percentage(double part, int percentage, int product_comp_sum_units)
{
	return percentage == (int)(std::round(part) / (product_comp_sum_units / 100.0));
}
/*
 * Standard rouding will not work as rounded number must still fit desired percentage from the whole sum
 */
inline void round_units_to_int(const InputVectorSimple& input, ResultVector& results, int product_comp_sum_units)
{
	double rounded_part;

	for (size_t i = 0; i < results.size(); i++)
	{
		rounded_part = results.at(i).second;
		if (is_part_correct_percentage(rounded_part, input[i].second, product_comp_sum_units))
			results[i].second = (int)(rounded_part);
		else if (is_part_correct_percentage(rounded_part + 1, input[i].second, product_comp_sum_units))
			results[i].second = (int)(rounded_part + 1);
		else
			throw std::exception();
	}
}
inline void normalize_units(ResultVector& results, int normalization_unit = 5)
{
	for (size_t i = 0; i < results.size(); i++)
	{
		results[i].second = results[i].second / normalization_unit;
	}
}
}

#endif // VINTAGE_STORY_TOOLS_HPP
