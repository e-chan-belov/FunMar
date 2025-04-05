#include <iostream>
#include <fstream>
#include "antlr4-runtime.h"
#include "FunMarCompiler.hpp"
#include "FunMarLexer.h"
#include "FunMarParser.h"
#include "Abstraction.hpp"
#include "Rule.hpp"

using namespace antlr4;

int main(int argc, char* argv[]) {
    std::ifstream stream;
    stream.open(FILE_PATH);
    if (!stream) {
        std::cerr << "Failed to open file\n";
        return 1;
    }

    ANTLRInputStream input(stream);
    FunMarLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    FunMarParser parser(&tokens);

    tree::ParseTree *tree = parser.prog();
    std::cout << "Parsed successfully: " << tree->toStringTree(&parser) << std::endl;

    FunMarCompiler visitor;
    FunMarParser::ProgContext *progCtx = dynamic_cast<FunMarParser::ProgContext *>(tree);
    if (progCtx) {
        visitor.visitProg(progCtx);
    }
    std::unordered_map<Variable, Statements> functions = visitor.compile();
    
    std::cout<<"COMPILED!" << std::endl;
    
    Statements mal = functions[(Variable)"ard"];
    Statements::Iterator iter = mal.begin();
    for (;iter.isAtList(); iter.next()) {
        if (iter.isRule()) {
            std::cout << iter.getRule().getInput().getStringRepresentation() << "->" << iter.getRule().getOutput().getStringRepresentation() << std::endl;
        }
        else {
            Scheme::Iterator schIter = iter.getSchemeBegin();
            std::cout << "SCHEME {" << std::endl;
            for (; schIter.isAtList(); schIter.next()) {
                std::cout << schIter.getRule().getInput().getStringRepresentation() << "->" << schIter.getRule().getOutput().getStringRepresentation() << std::endl;
            }
            std::cout << "}" << std::endl;
        }
    }
    
    //iter.next();
    //iter.next();
    
    //std::cout << iter.getRule().getInput().getStringRepresentation() << "->" << iter.getRule().getOutput().getStringRepresentation() << std::endl;
    return 0;
}

