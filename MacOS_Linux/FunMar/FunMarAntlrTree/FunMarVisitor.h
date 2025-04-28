
// Generated from FunMar.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "FunMarParser.h"
#include <any>



/**
 * This class defines an abstract visitor for a parse tree
 * produced by FunMarParser.
 */
class  FunMarVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by FunMarParser.
   */
    virtual std::any visitProg(FunMarParser::ProgContext *context) = 0;

    virtual std::any visitFunc(FunMarParser::FuncContext *context) = 0;

    virtual std::any visitExpStmt(FunMarParser::ExpStmtContext *context) = 0;

    virtual std::any visitStmt(FunMarParser::StmtContext *context) = 0;

    virtual std::any visitFunMarRule(FunMarParser::FunMarRuleContext *context) = 0;

    virtual std::any visitTerminalRule(FunMarParser::TerminalRuleContext *context) = 0;

    virtual std::any visitSchm(FunMarParser::SchmContext *context) = 0;

    virtual std::any visitSbwordi(FunMarParser::SbwordiContext *context) = 0;

    virtual std::any visitSbwordo(FunMarParser::SbwordoContext *context) = 0;

    virtual std::any visitAbst(FunMarParser::AbstContext *context) = 0;

    virtual std::any visitFuncAbst(FunMarParser::FuncAbstContext *context) = 0;


};

