/**
 * To find out, pair up the numbers and measure how far apart they are. 
 * Pair up the smallest number in the left list with the smallest number in the right list, then the second-smallest left number with the second-smallest right number, and so on.
 * Within each pair, figure out how far apart the two numbers are; you'll need to add up all of those distances. 
 * For example, if you pair up a 3 from the left list with a 7 from the right list, the distance apart is 4; if you pair up a 9 with a 3, the distance apart is 6.
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/foreach.hpp>
#include <algorithm>

int main() {
    std::ifstream f("day1_input.txt");
    if (!f.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    std::string s;
    std::vector<std::vector<std::string>> arr;
    while (getline(f, s)) {
        std::vector<std::string> line;
        boost::split(line, s, boost::is_space(), boost::token_compress_on);
        arr.push_back(line);
    }

    for (const auto &row: arr) {
        for (const auto &element: row)
            auto min = *std::max_element(std::begin(element), std::end(element));  
        std::cout << std::endl;
    }


    f.close();
    return 0;
}