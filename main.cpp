#include <iostream>
#include <fstream>
#include <sstream>
#include "days/days.h"

int main() {
	// std::ifstream file("input.txt"); 
    // std::vector<std::vector<int>> data;

    // if (file.is_open()) {
    //     std::string line;
    //     while (std::getline(file, line)) {
    //         std::vector<int> values;
    //         std::stringstream ss(line);
    //         int value;
    //         while (ss >> value) {
    //             values.push_back(value);
    //         }
    //         data.push_back(values);
    //     }
    //     file.close();
    // } else {
    //     std::cerr << "Error opening file." << std::endl;
    // }

    // // Example usage of the data
	// int total = 0;
    // for (auto row : data) {
	// 	total += day2::safeLevels(row);
    // }

	// std::cout << total << "\n";
	// return 1;

    std::vector<std::string>out = day3::readInput();
    int total = 0;
    for (size_t i = 0; i < out.size(); i++) {
        total += day3::parseLine(out[i]);
    }
    std::cout << "Total = " << total << "\n"; 

    return 1;
}
