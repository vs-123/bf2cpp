#include <iostream>
#include <fstream>
#include <string>

#include "bf.h"

int main(int argc, char **argv) {
    if (argc != 3) {
        std::cout << "[Usage] " << argv[0] << " <input_file> <output_file>" << std::endl;
        std::cout << "[Example] " << argv[0] << " test.bf test.cpp" << std::endl;
        return 1;
    }

    std::ifstream sourceCodeStream(argv[1]);
    std::string sourceCode = {std::istreambuf_iterator<char>(sourceCodeStream), {}};
    sourceCodeStream.close();

    std::string compiled = compile(sourceCode);

    std::ofstream targetFile(argv[2]);
    targetFile << compiled;

    targetFile.close();

    return 0;
}