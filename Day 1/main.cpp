#include <bits/stdc++.h>
#include <iostream>
#include <cmath>

std::pair<std::vector<int>, std::vector<int>> ReadData(std::string& filename) {
    std::ifstream file(filename);
    std::string line;

    std::vector<int> arr_l, arr_r;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int left, right;

        if (iss >> left >> right) {
            arr_l.push_back(left);
            arr_r.push_back(right);
        }
    }
    return std::make_pair(arr_l, arr_r);
}

int PartOne(std::string& filename) {
    auto [arr_l, arr_r] = ReadData(filename);
    std::sort(arr_l.begin(), arr_l.end());
    std::sort(arr_r.begin(), arr_r.end());

    int accumulator = 0;
    for (int i = 0; i < arr_l.size(); i++) {
        //std::cout << arr_l[i] << " , " << arr_r[i] << std::endl;
        accumulator += std::abs(arr_l[i] - arr_r[i]);
    }

    return accumulator;
}

int PartTwo(std::string& filename) {
    auto [arr_l, arr_r] = ReadData(filename);
    std::sort(arr_l.begin(), arr_l.end());
    std::sort(arr_r.begin(), arr_r.end());

    int accumulator = 0;
    for (int i : arr_l) {
        const int count = std::count(arr_r.begin(), arr_r.end(), i);
        accumulator += i * count;
    }

    return accumulator;
}


int main() {
    std::string filename = "input.txt";
    std::cout << "Part One: " << PartOne(filename)<< std::endl;
    std::cout << "Part Two: " << PartTwo(filename)<< std::endl;
}

