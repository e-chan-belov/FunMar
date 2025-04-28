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

int main() {
    std::ifstream stream;
    stream.open(std::string(FILE_PATH) + "main.fm");
    if (!stream) {
        std::cerr << "Failed to open main.fm file\n";
        return 1;
    }

    ANTLRInputStream input(stream);
    FunMarLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    FunMarParser parser(&tokens);

    tree::ParseTree *tree = parser.prog();
    //std::cout << "Parsed successfully: " << tree->toStringTree(&parser) << std::endl;

    FunMarCompiler visitor;
    FunMarParser::ProgContext *progCtx = dynamic_cast<FunMarParser::ProgContext *>(tree);
    if (progCtx) {
        visitor.visitProg(progCtx);
    }
    std::unordered_map<Variable, Statements> functions = visitor.compile();
    
    std::cout<<"\nCOMPILED!" << std::endl;
    
    /*Statements mal = functions[(Variable)"main"];
    Statements::ObserverIterator iter = mal.begin();
    for (;iter.isAtList(); iter.next()) {
        if (iter.isRule()) {
            std::cout << iter.getRule().getStringRepresentation() << std::endl;
        }
        else {
            Scheme::ObserverIterator schIter = iter.getSchemeBegin();
            std::cout << "SCHEME {" << std::endl;
            for (; schIter.isAtList(); schIter.next()) {
                std::cout << schIter.getRule().getStringRepresentation() << std::endl;
            }
            std::cout << "}" << std::endl;
        }
    }*/
    std::cout << "\nWould you like to enter your word or use input.txt file as a word?" << std::endl;
    std::cout << "\nEnter 'Word' or 'File'" << std::endl;
    std::string choice;
    std::cin >> choice;
    Word word;
    if (choice == "File" or choice == "file") {
        word = readFileToString(std::string(FILE_PATH) + "input.txt");
    }
    else {
        std::cout << "Enter your word" << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, word);
    }
    Kernel kernel(functions);
    
    std::cout << "Answer:" << std::endl;
    std::cout << kernel.execute(word) << std::endl;
    
    return 0;
}

