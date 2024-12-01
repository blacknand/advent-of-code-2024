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
#include <cmath>
#include <unordered_map>

int main() {
    std::ifstream f("day1_input.txt");
    if (!f.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    // Split each line into 2 seperate elements inside of vector line
    std::string s;
    std::vector<std::string> arr1;
    std::vector<std::string> arr2;
    while (getline(f, s)) {
        std::vector<std::string> tokens;
        boost::split(tokens, s, boost::is_space(), boost::token_compress_on);

        arr1.push_back(tokens[0]);
        arr2.push_back(tokens[1]);
    }
    f.close();

    // Convert from string to integers
    std::vector<int> int_arr1;
    std::vector<int> int_arr2;
    std::transform(arr1.begin(), arr1.end(), std::back_inserter(int_arr1), [](const std::string &str) {return std::stoi(str);});
    std::transform(arr2.begin(), arr2.end(), std::back_inserter(int_arr2), [](const std::string &str) {return std::stoi(str);});

    std::sort(int_arr1.begin(), int_arr1.end());
    std::sort(int_arr2.begin(), int_arr2.end());

    int total_distance = 0;
    for (size_t i = 0; i < int_arr1.size(); ++i) {
        total_distance += std::abs(int_arr1[i] - int_arr2[i]);
    }

    std::cout << "Total difference: " << total_distance << std::endl;

    /**
     * you'll need to figure out exactly how often each number from the left list appears in the right list. 
     * Calculate a total similarity score by adding up each number in the left list after multiplying it by the number of times that number appears in the right list.
     */

    typedef std::unordered_map<int, int> counter_map;
    counter_map counts;

    for (auto i: int_arr1) {
        auto it = counts.find(i);
        if (it != counts.end())
            it->second++;
        else
            counts[i] = 1;
    }

    int similarity_score = 0;
    for (auto i: int_arr2) {
        auto it = counts.find(i);
        if (it != counts.end())
            similarity_score += i * it->second;
    }

    std::cout << "Total similarity score: " << similarity_score << std::endl;

    f.close();
    return 0;
}