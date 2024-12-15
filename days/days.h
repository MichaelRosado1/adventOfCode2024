#pragma once

#include <vector>
#include <algorithm>
#include <math.h> 
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>



namespace day1 { 
	int findDistancesFromInputs(std::vector<int>& input1, std::vector<int>& input2); 
	int occurencesOfValues(std::vector<int>& input1, std::vector<int>& input2); 
}

namespace day2 {
	int findGoodLevels(std::vector<int>& input);
	int findGoodLevelsTwo(std::vector<int>& input);
	int checkSafe(int i, std::vector<int> input, bool isIncreasing);
	bool checkDecreasing(std::vector<int>& input);
	int safeLevels(std::vector<int>& input);
}

namespace day3 {
	std::vector<std::string> readInput();
	int parseLine(std::string line);
}