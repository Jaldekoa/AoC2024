#include <bits/stdc++.h>
#include <iostream>

std::string ReadData(const std::string& filename) {
    const std::ifstream file(filename, std::ios::binary);
    std::ostringstream input_data;
    input_data << file.rdbuf();

    return input_data.str();
}

std::vector<std::smatch> Tokenizer(std::string& string) {
    const std::regex regex(R"(do\(\)|don't\(\)|mul\((\d+),(\d+)\))");
    std::sregex_iterator it(string.begin(), string.end(), regex);

    std::vector<std::smatch> matches;
    for (const std::sregex_iterator end; it != end; ++it) {
        matches.emplace_back(*it);
    }

    return matches;
}

int PartOne (const std::string& filename) {
    std::string input_data = ReadData(filename);
    const std::vector<std::smatch> tokens = Tokenizer(input_data);

    int result = 0;
    for (const auto& token : tokens) {
        if (!token[1].str().empty() && !token[2].str().empty())
            result += std::stoi(token[1].str()) * std::stoi(token[2].str());
    }

    return result;
}

int PartTwo (const std::string& filename) {
    std::string input_data = ReadData(filename);
    const std::vector<std::smatch> tokens = Tokenizer(input_data);

    int result = 0;
    bool enabled = true;
    for (const auto& token : tokens) {
        if (!token[1].str().empty() && !token[2].str().empty() && enabled)
            result += std::stoi(token[1].str()) * std::stoi(token[2].str());
        else if (token[0].str() == "don't()")
            enabled = false;
        else if (token[0].str() == "do()")
            enabled = true;
    }

    return result;
}

int main() {
    const std::string filename = "input.txt";
    std::cout << "Part One: " << PartOne(filename)<< std::endl;
    std::cout << "Part Two: " << PartTwo(filename)<< std::endl;
    return 0;
}