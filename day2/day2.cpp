/**
 * The Red-Nosed reactor safety systems can only tolerate levels that are either gradually increasing or gradually decreasing. 
 * So, a report only counts as safe if both of the following are true:
 *      The levels are either all increasing or all decreasing.
 *      Any two adjacent levels differ by at least one and at most three.
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/foreach.hpp>

int main() {
    std::ifstream f("day2_input.txt");
    if (!f.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    std::string s;
    int safe = 0;
    while (getline(f, s)) {
        std::vector<std::string> tokens;
        boost::split(tokens, s, boost::is_space(), boost::token_compress_on);
        std::vector<int> int_arr;
        std::transform(tokens.begin(), tokens.end(), std::back_inserter(int_arr), [](const std::string &str) {return std::stoi(str);});

        bool unsafe = false;
        for (size_t i = 0; i < int_arr.size() - 1; i++) {
            if (!(int_arr[i] > int_arr[i + 1] and std::abs(int_arr[i] - int_arr[i + 1]) >= 1 && std::abs(int_arr[i] - int_arr[i + 1]) <= 3)) {
                unsafe = true;
                break;
            }
        }
        
        for (auto i: int_arr)
            std::cout << i << " -->";
        std::cout << unsafe << std::endl;        
        if (!(unsafe))
            safe++;
    }

    std::cout << "Safe reports: " << safe << std::endl;
    return 0;
}