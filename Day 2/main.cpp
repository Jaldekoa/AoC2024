#include <bits/stdc++.h>
#include <iostream>

std::vector<std::vector<int>> ReadData(std::string& filename) {
    std::ifstream file(filename);
    std::string line;

    std::vector<std::vector<int>> input_data;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::vector<int> report;

        int level;

        while(iss >> level) {
            report.push_back(level);
        }
        input_data.push_back(report);
    }

    return input_data;
}

bool IsValidReport(const std::vector<int>& report) {
    std::vector<int> diffs; //(report.size() - 1);

    for (int i = 1; i < report.size(); ++i) {
        diffs.push_back(report[i] - report[i-1]);
    }

    bool is_increasing = true, is_decreasing = true;
    for (const int& diff : diffs) {
        is_increasing = is_increasing && (1 <= diff && diff <= 3);
        is_decreasing = is_decreasing && (-3 <= diff && diff <= -1);
    }

    return is_increasing || is_decreasing;
}

// Adapted from Rosetta Code: https://rosettacode.org/wiki/Combinations#C.2B.2B
std::vector<std::vector<int>> combinations(const std::vector<int>& elements, const std::size_t& K) {
    std::vector<std::vector<int>> result;

    std::string bitmask(K, 1);
    bitmask.resize(elements.size(), 0);

    do {
        std::vector<int> combination;
        for (int i = 0; i < elements.size(); ++i) {
            if (bitmask[i])
                combination.push_back(elements[i]);
        }
        result.push_back(combination);
    } while (std::prev_permutation(bitmask.begin(), bitmask.end()));

    return result;
}

int PartOne(std::string& filename) {
    std::vector<std::vector<int>> input_data = ReadData(filename);

    int num_valid_reports = 0;
    for (const auto& report : input_data) {
        num_valid_reports += static_cast<int>(IsValidReport(report));
    }

    return num_valid_reports;
}

int PartTwo(std::string& filename) {
    std::vector<std::vector<int>> input_data = ReadData(filename);

    int num_valid_reports = 0;
    for (const auto& report : input_data) {
        std::vector<std::vector<int>> combs = combinations(report, report.size() - 1);

        bool some_valid_report = false;
        for (const auto& comb : combs) {
            some_valid_report |= IsValidReport(comb);
            if (some_valid_report)
                break;
        }
        num_valid_reports += static_cast<int>(some_valid_report);
    }

    return num_valid_reports;
}

int main() {
    std::string filename = "input.txt";
    std::cout << "Part One: " << PartOne(filename)<< std::endl;
    std::cout << "Part Two: " << PartTwo(filename)<< std::endl;
}