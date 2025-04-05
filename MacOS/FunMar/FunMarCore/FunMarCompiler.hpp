#pragma once


#include "antlr4-runtime.h"
#include "FunMarBaseVisitor.hpp"
#include "FunctionAbstraction.hpp"
#include "Rule.hpp"


class FunMarCompiler : public FunMarBaseVisitor {
private:
    std::unordered_map<Variable, Statements> functions;
    AbstractionGenerator abstractionGenerator;
    FunctionAbstractionGenerator functionAbstractionGenerator;
    SchemeGenerator schemeGenerator;
    StatementsGenerator statementsGenerator;
public:

  virtual std::any visitProg(FunMarParser::ProgContext *ctx) override {
      for (auto* funcCtx : ctx->func()) {
          visitFunc(funcCtx);
      }
      return nullptr;
  }

  virtual std::any visitFunc(FunMarParser::FuncContext *ctx) override {
      Variable var = ctx->ID()->getText();
      for (auto* stmtCtx : ctx->expStmt()) {
          std::any expstmt = visitExpStmt(stmtCtx);
          if (expstmt.type() == typeid(Rule)) {
              statementsGenerator.push(std::any_cast<Rule>(expstmt));
          }
          else {
              statementsGenerator.push(std::any_cast<Scheme>(expstmt));
          }// scheme or rule
      }
      functions[var] = std::any_cast<Statements>(statementsGenerator.generate()); // Statements
      return nullptr;
  }

  virtual std::any visitExpStmt(FunMarParser::ExpStmtContext *ctx) override {
      if (ctx->stmt()) {
          return visitStmt(ctx->stmt()); // rule
      }
      else if (ctx->schm()) {
          return visitSchm(ctx->schm()); // scheme
      }
      return nullptr;
  }

  virtual std::any visitStmt(FunMarParser::StmtContext *ctx) override {
    if (ctx->funMarRule()) {
        return visitFunMarRule(ctx->funMarRule()); // rule
    }
    else if (ctx->terminalRule()) {
        return visitTerminalRule(ctx->terminalRule()); // rule
    }
    return nullptr;
  }

  virtual std::any visitFunMarRule(FunMarParser::FunMarRuleContext *ctx) override {
    Abstraction sbwordi = std::any_cast<Abstraction>(visitSbwordi(ctx->sbwordi()));
    FunctionAbstraction sbwordo = std::any_cast<FunctionAbstraction>(visitSbwordo(ctx->sbwordo()));
    return Rule(sbwordi, sbwordo, false);
  }

  virtual std::any visitTerminalRule(FunMarParser::TerminalRuleContext *ctx) override {
    Abstraction sbwordi = std::any_cast<Abstraction>(visitSbwordi(ctx->sbwordi()));
    FunctionAbstraction sbwordo = std::any_cast<FunctionAbstraction>(visitSbwordo(ctx->sbwordo()));
    return Rule(sbwordi, sbwordo, true);
  }

  virtual std::any visitSchm(FunMarParser::SchmContext *ctx) override {
      for (auto* stmtCtx : ctx->stmt()) {
          schemeGenerator.push(std::any_cast<Rule>(visitStmt(stmtCtx))); // rule
      }
      return schemeGenerator.generate(); // scheme
  }

  virtual std::any visitSbwordi(FunMarParser::SbwordiContext *ctx) override {
      for (auto token : ctx->children) {
          if (auto obj = dynamic_cast<antlr4::tree::TerminalNode*>(token)) {
              if (obj->getSymbol()->getType() == 9) { // костыль
                  std::string strr = obj->getText();
                  strr = strr.substr(1, strr.size() - 2);
                  abstractionGenerator.push((Word)(strr));
              }
              else {
                  abstractionGenerator.push((Variable)(obj->getText()));
              }
          }
      }
      return abstractionGenerator.generate(); // abstraction
  }

  virtual std::any visitSbwordo(FunMarParser::SbwordoContext *ctx) override {
      for (auto token : ctx->children) {
          if (auto let = dynamic_cast<antlr4::tree::TerminalNode*>(token)) {
              std::string strr = let->getText();
              strr = strr.substr(1, strr.size() - 2);
            functionAbstractionGenerator.push((Word)(strr));
          }
          else if (auto funCall = dynamic_cast<FunMarParser::FunCallContext*>(token)) {
              std::any funelem = visitFunCall(funCall);
              if (funelem.type() == typeid(Variable)) {
                  functionAbstractionGenerator.push(std::any_cast<Variable>(funelem));
              }
              else {
                  functionAbstractionGenerator.push(std::any_cast<Function>(funelem));
              } // id or abstraction
          }
      }
      return functionAbstractionGenerator.generate(); // functionabstraction
  }

  virtual std::any visitFunCall(FunMarParser::FunCallContext *ctx) override {
      if (ctx->children.size() == 1) {
          return (Variable)(ctx->ID()->getText());
      }
      else {
          Variable var = ctx->ID()->getText();
          Abstraction arg = std::any_cast<Abstraction>(visitSbwordi(ctx->sbwordi()));
          return Function(var, arg);
      }
  }

    std::unordered_map<Variable, Statements>& compile() {
        return functions;
    }
};

