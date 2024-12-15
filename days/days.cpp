#include "days.h"

namespace day1 { 
	int findDistancesFromInputs(std::vector<int>& input1, std::vector<int>& input2) {
		std::sort(input1.begin(), input1.end());
		std::sort(input2.begin(), input2.end());

		// input 1 is sorted and input 2 is sorted
		int totalDistance = 0;
		for (size_t i = 0; i < input1.size(); i++) {
			int distance = std::abs(input1[i] - input2[i]);
			totalDistance += distance; 
		}

		return totalDistance;
	}

	int occurencesOfValues(std::vector<int>& input1, std::vector<int>& input2) {
		std::unordered_map<int, int> rightNums; 

		for (size_t i = 0; i < input2.size(); i++) {
			if (rightNums.find(input2[i]) != rightNums.end()) { 
				rightNums[input2[i]]++;
			} else {
				rightNums[input2[i]] = 1;
			}
		}				
		int total = 0;
		for (size_t i = 0; i < input1.size(); i++) {
			if (rightNums.find(input1[i]) != rightNums.end()) {
				total += (input1[i] * rightNums[input1[i]]);
			}
		}

		return total;
	}
}

namespace day2 {
	/*
		if i have a list of nums like this
			8, 2, 3, 4, 5, 6
			1,2,3,2,5
			8, 6, 7, 8

			I could keep a count of how many times we increase in the array and how many times we decrease
			for ex

			1, 2, 3, 4, 5
			
			6, 7, 5, 8, 9
			[1, -2, 3, 1] posNums = 3, negNums = 1

			while I build the array, I can keep track of the number of positive and negative changes and that will tell me whether the array is mostly pos
			or mostly neg

			then I know that if there are more than one of the opposing majority, 2 negatives to 3 positives, then that means this is unsafe

			if theres 3 and 1 or 1 and 3, then I can go through the array to find the value, or keep track of the index and send to another func
			and thats when I can do the check if I can remove the level or not

	*/
	int checkSafe(int i, std::vector<int> input, bool isIncreasing) {
		// we want to check if this negative index can be removed saftly 
		if (i > 0 && i < input.size() - 1) {
			int newDiff = std::abs(input[i + 1] - input[i - 1]);
			if (newDiff >= 1 && newDiff <= 3) {
				return 1;
			} else {
				return 0;
			} 
		}
		return 0;
	}

	int findGoodLevelsTwo(std::vector<int>& input) {
		int posNums = 0;
		int negNums = 0;
		int lastPosIndex = 0;
		int lastNegIndex = 0;
		std::vector<int> diffVect;

		for (size_t i = 0; i < input.size() - 1; i++) {
			int diff = input[i + 1] - input[i];
			if (diff >= 1) {
				posNums++;
				lastPosIndex = i;
			} else if (diff < 0) {
				negNums++;
				lastNegIndex = i;
			} else {
				// this is when the diff is 0 which means this isn't a good level I believe
				return 0;
			}
		}

		if (posNums > negNums && negNums == 1) {
			// this is where we might be able to get access to the - num	
			return checkSafe(lastNegIndex, input, true);
		} else if (negNums > posNums && posNums == 1) {
			return checkSafe(lastPosIndex, input, false);
		} else if (negNums > 1 && posNums > 1) {
			return 0;
		}
	}

	// int findGoodLevels(std::vector<int>& input) {
	// 	if (checkIncreasing(input) || checkDecreasing(input)) {
	// 		return 1;
	// 	}
	// 	return 0;
	// }

	// bool checkIncreasing(std::vector<int>& input) {
	// 	// increasing means that every element is greater than the previous
	// 	int unsafeLevels = 0;
	// 	for (size_t i = 1; i < input.size(); i++) {
	// 		if (input[i] < input[i - 1]) {
	// 			return false;
	// 		} 
	// 		// if the values differ by at least one and at most three
	// 		int dist = input[i] - input[i - 1];
	// 		if (dist >= 1 && dist <= 3) {
	// 			continue;
	// 		} else {
	// 			unsafeLevels += checkSafe(i, input);
	// 		}
	// 	}

	// 	if (unsafeLevels <= 1) {
	// 		return true;
	// 	} 
	// 	return false;
	// }

	// bool checkDecreasing(std::vector<int>& input) {
	// 	int unsafeLevels = 0;
	// 	// decreasing means that every element is smaller than the previous
	// 	for (size_t i = 1; i < input.size(); i++) {
	// 		if (input[i] > input[i - 1]) {
	// 			return false;
	// 		} 
	// 		// if the values differ by at least one and at most three
	// 		int dist = std::abs(input[i] - input[i - 1]);
	// 		if (dist >= 1 && dist <= 3) {
	// 			continue;
	// 		} else {
	// 			unsafeLevels += checkSafe(i, input);
	// 		}
	// 	}
	// 	if (unsafeLevels <= 1) {
	// 		return true;
	// 	}
	// 	return false;
	// }

	int safeLevels(std::vector<int>& input) {
		std::vector<int> diffVect;
		int numPos, numNeg;
		int zeroValues = 0;
		numPos = numNeg = 0, 0;
		int lastNegIndex, lastPosIndex;
		lastNegIndex = lastPosIndex = 0;
		for (size_t i = 0; i < input.size() - 1; i++) {
			int diff = input[i + 1] - input[i];
			// this gives me the change from i to i + 1
			if (diff > 0) {
				numPos++;
				lastPosIndex = i + 1;
			} else if (diff < 0) {
				numNeg++;
				lastNegIndex = i + 1;
			} else {
				zeroValues++;
			}
			diffVect.push_back(diff);
		}

		// so now I have the diff vect which is one smaller than the vector
		// not safe since there aren't enough removals 
		if (numPos > 1 && numNeg > 1) {
			return 0;
		}


		if (numPos > 0 && numNeg == 0 && zeroValues == 0) {
			return 1;
		}
		if (numNeg > 0 && numPos == 0 && zeroValues == 0) {
			return 1;
		}

		if (numNeg == 1 && zeroValues == 0) {
			int newDiff = std::abs(input[lastNegIndex + 1] - input[lastNegIndex - 1]);
			// 1, 2, 3, 4
			//   [1, -2, 1]
			if (newDiff >= 1 && newDiff <= 3) {
				return 1;
			}
			return 0;
		} else {
			if (zeroValues == 0) {
				int newDiff = std::abs(input[lastPosIndex + 1] - input[lastPosIndex - 1]);
				if (newDiff >= 1 && newDiff <= 3) {
					return 1;
				}
				return 0;
			}
		} 
		return 0;
	}
}


namespace day3 {
	std::vector<std::string> readInput() {
		std::vector<std::string> out;
		std::ifstream file("input.txt");
		std::string line;
		while (std::getline(file, line)) {
			out.push_back(line);
		}
		return out;
	}

	std::vector<int> getNums(int index, std::string line) {
		if (index >= line.size()) {
			return {};
		}
		std::string firstNum = "";
		std::string secondNum = "";
		bool commaNotEncountered = true;
		if (line[index] == '(') {
			for (int i = index + 1; i < line.size(); i++) {
				if (line[i] == ' ') {
					continue;
				}
				if (line[i] == ',' && commaNotEncountered) {
					commaNotEncountered = false;
				} else if (isdigit(line[i])) {
					if (commaNotEncountered) {
						firstNum += (line[i]);
					} else {
						secondNum += (line[i]);
					}
				} else if (line[i] == ')' && firstNum.length() > 0 && secondNum.length() > 0) {
					std::cout << firstNum << " " << secondNum << "\n";
					return  {std::stoi(firstNum), std::stoi(secondNum)};
				} else {
					return {};
				}
			}
		} 
		return {};
		
	}

	/*std::vector<std::vector<int>>*/ int parseLine(std::string line) {
		std::string mul = "mul";
		int total = 0;
		for (size_t i = 0; i < line.length(); i++) {
			if (line[i] == 'm') {
				if (line.substr(i, 3) == mul) {
					// I have the index of m
					// index + 2 is the start of the rest of the string
					std::vector<int> nums = getNums(i + 3, line);
					if (nums.size() == 2) {
						total += (nums[0] * nums[1]);
					}
					
				}
			}
		}
		return total;
	}
}

