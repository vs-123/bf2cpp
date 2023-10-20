#include <iostream>
#include <unordered_map>
#include <functional>

#include "bf.h"

std::string compile(const std::string& sourceCode) {
    std::string output = "#define MAX_CELLS 30000\n#include <iostream>\nint main() {\n    size_t cells[MAX_CELLS];\n    size_t currentCell = MAX_CELLS/2;\n";
    size_t tab_count = 1;

    std::unordered_map<char, std::function<std::string()>> commandMap = {
        {'-', [&]() { return std::string(tab_count*4, ' ') + "--cells[currentCell];\n"; }},
        {'+', [&]() { return std::string(tab_count*4, ' ') + "++cells[currentCell];\n"; }},
        {'>', [&]() { return std::string(tab_count*4, ' ') + "++currentCell;\n"; }},
        {'<', [&]() { return std::string(tab_count*4, ' ') + "--currentCell;\n"; }},
        {'[', [&]() { return std::string((tab_count++)*4, ' ') + "while (cells[currentCell] != 0) {\n"; }},
        {']', [&]() { tab_count--; return std::string(tab_count*4, ' ') + "}\n"; }},
        {'.', [&]() { return std::string(tab_count*4, ' ') + "std::cout << char(cells[currentCell]);\n"; }},
        {',', [&]() { return std::string(tab_count*4, ' ') + "std::cin >> cells[currentCell];\n"; }}
    };

    for (auto character : sourceCode) {
        if (commandMap.count(character)) {
            output += commandMap[character]();
        } else if (character != '\n' && character != ' ' && character != '\t') {
            std::cerr << "[Warning] Skipped unknown character: " << character << std::endl;
        }
    }

    output += "\n}";

    return output;
}
