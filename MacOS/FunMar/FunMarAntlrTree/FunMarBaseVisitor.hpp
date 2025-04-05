
// Generated from FunMar.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "FunMarVisitor.h"


/**
 * This class provides an empty implementation of FunMarVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  FunMarBaseVisitor : public FunMarVisitor {
public:

  virtual std::any visitProg(FunMarParser::ProgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunc(FunMarParser::FuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpStmt(FunMarParser::ExpStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmt(FunMarParser::StmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunMarRule(FunMarParser::FunMarRuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTerminalRule(FunMarParser::TerminalRuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSchm(FunMarParser::SchmContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSbwordi(FunMarParser::SbwordiContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSbwordo(FunMarParser::SbwordoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunCall(FunMarParser::FunCallContext *ctx) override {
    return visitChildren(ctx);
  }


};

