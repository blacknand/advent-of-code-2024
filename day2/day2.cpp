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
    int lines = 0;
    while (getline(f, s)) {
        std::vector<std::string> tokens;
        boost::split(tokens, s, boost::is_space(), boost::token_compress_on);
        std::vector<int> int_arr;
        std::transform(tokens.begin(), tokens.end(), std::back_inserter(int_arr), [](const std::string &str) {return std::stoi(str);});

        bool unsafe = false;
        bool increasing = int_arr[0] < int_arr[1];
        for (size_t i = 0; i < int_arr.size() - 1; i++) {
            int dist = std::abs(int_arr[i] - int_arr[i + 1]);

            if ((increasing && int_arr[i] >= int_arr[i + 1]) || (!increasing && int_arr[i] <= int_arr[i + 1]) || dist < 1 || dist > 3) {
                unsafe = true;
                break;
            } 
        }
        
        for (auto i: int_arr)
            std::cout << i;
        std::cout << " --> " << unsafe << std::endl;        
        if (!(unsafe))
            safe++;
        lines++;
    }

    std::cout << "Safe reports: " << safe << "  Lines " << lines << std::endl;
    f.close();
    return 0;
}