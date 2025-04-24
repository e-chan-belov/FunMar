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
      for (auto* stmtCtx : ctx->expStmt()) {
          schemeGenerator.push(std::any_cast<Rule>(visitExpStmt(stmtCtx))); // rule
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
      for (auto abst : ctx->funcAbst()) {
          auto value = visitFuncAbst(abst);
          if (value.type() == typeid(Word)) { functionAbstractionGenerator.push(std::any_cast<Word>(value)); }
          else if (value.type() == typeid(Variable)) { functionAbstractionGenerator.push(std::any_cast<Variable>(value)); }
          else { functionAbstractionGenerator.push(std::any_cast<Function>(value)); }
      }
      return functionAbstractionGenerator.generate(); // functionabstraction
  }
    
    virtual std::any visitAbst(FunMarParser::AbstContext *ctx) override {
        if (ctx->LET()) {
            std::string strrr = ctx->LET()->getText();
            return (Word)strrr.substr(1, strrr.size() - 2);
        }
        else if (ctx->ID()) { return (Variable)ctx->ID()->getText(); }
        return nullptr;
    }

    virtual std::any visitFuncAbst(FunMarParser::FuncAbstContext *ctx) override {
        if (ctx->LET()) {
            std::string strrr = ctx->LET()->getText();
            return (Word)strrr.substr(1, strrr.size() - 2);
        }
        else if (ctx->children.size() == 1) {
            return (Variable)(ctx->ID()->getText());
        }
        else {
            Variable var = ctx->ID()->getText();
            for (auto abstr : ctx->abst()) {
                auto value = visitAbst(abstr);
                if (value.type() == typeid(Word)) {
                    abstractionGenerator.push(std::any_cast<Word>(value));
                }
                else {
                    abstractionGenerator.push(std::any_cast<Variable>(value));
                }
            }
            Abstraction arg = abstractionGenerator.generate();
            return Function(var, arg);
        }
    }

  /*virtual std::any visitFunCall(FunMarParser::FunCallContext *ctx) override {
      if (ctx->children.size() == 1) {
          return (Variable)(ctx->ID()->getText());
      }
      else {
          Variable var = ctx->ID()->getText();
          Abstraction arg = std::any_cast<Abstraction>(visitSbwordi(ctx->sbwordi()));
          return Function(var, arg);
      }
  }*/

    std::unordered_map<Variable, Statements>& compile() {
        return functions;
    }
};

