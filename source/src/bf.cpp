#include <iostream>

#include "bf.h"

std::string compile(std::string sourceCode) {
    std::string output = "#define MAX_CELLS 30000\n#include <iostream>\nint main() {\nsize_t cells[MAX_CELLS];\nsize_t currentCell = MAX_CELLS/2;\n";

    for (char &character : sourceCode) {
        switch (character) {
            case '\n':
            case ' ':
            case '\t':
                continue;
                break;

            case '+':
                output += "cells[currentCell]++;\n";
                break;

            case '-':
                output += "cells[currentCell]--;\n";
                break;
            
            case '>':
                output += "currentCell++;\n";
                break;
            
            case '<':
                output += "currentCell--;\n";
                break;
            
            case '[':
                output += "do {\n";
                break;
            
            case ']':
                output += "}\nwhile(cells[currentCell] != 0);\n";
                break;
            
            case '.':
                output += "std::cout << char(cells[currentCell]);\n";
                break;
            
            case ',':
                output += "std::cin >> cells[currentCell];\n";
                break;
            
            default:
                std::cout << "[Warning] Skipped unknown character: " << character << std::endl;
                break;
        }
    }

    output += "\n}";

    return output;
}