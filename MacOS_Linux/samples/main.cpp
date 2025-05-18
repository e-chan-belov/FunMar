#include <iostream>
#include <fstream>
#include "antlr4-runtime.h"
#include "FunMarCompiler.hpp"
#include "FunMarLexer.h"
#include "FunMarParser.h"
#include "Abstraction.hpp"
#include "Rule.hpp"
#include "Kernel.hpp"

using namespace antlr4;

Word readFileToString(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary | std::ios::ate);
    if (!file) {
        throw std::runtime_error("Не удалось открыть файл: " + filename);
    }

    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);

    std::string buffer(size, '\0');
    if (!file.read(&buffer[0], size)) {
        throw std::runtime_error("Ошибка чтения файла: " + filename);
    }

    return buffer;
}

bool endsWith(const std::string& str, const std::string& suffix) {
    return str.size() >= suffix.size() &&
           str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}

int main(int argc, char** argv) {
    Word word = "";
    std::string inputName = "";
    bool isReceived = false;
    std::string progName = "main.fm";
    
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if ((arg == "-f" || arg == "-File") && i + 1 < argc) {
            if (isReceived) {
                std::cerr << "Invalid input " << arg << std::endl;
                return -1;
            }
            inputName = argv[++i];
            isReceived = true;
        } else if ((arg == "-w" || arg == "-Word") && i + 1 < argc) {
            if (isReceived) {
                std::cerr << "Invalid input " << arg << std::endl;
                return -1;
            }
            word = argv[++i];
            isReceived = true;
        } else if (endsWith(arg, ".fm")) {
            progName = arg;
        } else {
            std::cerr << "Invalid input" << arg << std::endl;
            return -1;
        }
    }
    
    std::ifstream stream;
    stream.open(std::string(FILE_PATH) + progName);
    if (!stream) {
        std::cerr << "Failed to open .fm file\n";
        return -1;
    }

    ANTLRInputStream input(stream);
    FunMarLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    FunMarParser parser(&tokens);

    tree::ParseTree *tree = parser.prog();
    FunMarCompiler visitor;
    FunMarParser::ProgContext *progCtx = dynamic_cast<FunMarParser::ProgContext *>(tree);
    if (progCtx) {
        visitor.visitProg(progCtx);
    }
    std::unordered_map<Variable, Statements> functions = visitor.compile();
    
    Kernel kernel(functions);
    
    if (isReceived) {
        if (!inputName.empty()) {
            word = readFileToString(std::string(FILE_PATH) + "input.txt");
        }
        std::cout << kernel.execute(word) << std::endl;
    }
    else {
        std::cout << "\nWould you like to enter your word or use input.txt file as a word?" << std::endl;
        std::cout << "\nEnter 'Word' or 'File'" << std::endl;
        std::string choice;
        std::cin >> choice;
        if (choice == "File" or choice == "file") {
            word = readFileToString(std::string(FILE_PATH) + "input.txt");
        }
        else {
            std::cout << "Enter your word" << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, word);
        }
        
        
        std::cout << "Answer:" << std::endl;
        std::cout << kernel.execute(word) << std::endl;
    }
        return 0;
}

