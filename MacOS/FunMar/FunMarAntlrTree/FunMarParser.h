
// Generated from FunMar.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  FunMarParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, LET = 9, ID = 10, WS = 11
  };

  enum {
    RuleProg = 0, RuleFunc = 1, RuleExpStmt = 2, RuleStmt = 3, RuleFunMarRule = 4, 
    RuleTerminalRule = 5, RuleSchm = 6, RuleSbwordi = 7, RuleSbwordo = 8, 
    RuleFunCall = 9
  };

  explicit FunMarParser(antlr4::TokenStream *input);

  FunMarParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~FunMarParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class ProgContext;
  class FuncContext;
  class ExpStmtContext;
  class StmtContext;
  class FunMarRuleContext;
  class TerminalRuleContext;
  class SchmContext;
  class SbwordiContext;
  class SbwordoContext;
  class FunCallContext; 

  class  ProgContext : public antlr4::ParserRuleContext {
  public:
    ProgContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<FuncContext *> func();
    FuncContext* func(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgContext* prog();

  class  FuncContext : public antlr4::ParserRuleContext {
  public:
    FuncContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    std::vector<ExpStmtContext *> expStmt();
    ExpStmtContext* expStmt(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FuncContext* func();

  class  ExpStmtContext : public antlr4::ParserRuleContext {
  public:
    ExpStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StmtContext *stmt();
    SchmContext *schm();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpStmtContext* expStmt();

  class  StmtContext : public antlr4::ParserRuleContext {
  public:
    StmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FunMarRuleContext *funMarRule();
    TerminalRuleContext *terminalRule();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StmtContext* stmt();

  class  FunMarRuleContext : public antlr4::ParserRuleContext {
  public:
    FunMarRuleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SbwordiContext *sbwordi();
    SbwordoContext *sbwordo();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunMarRuleContext* funMarRule();

  class  TerminalRuleContext : public antlr4::ParserRuleContext {
  public:
    TerminalRuleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SbwordiContext *sbwordi();
    SbwordoContext *sbwordo();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TerminalRuleContext* terminalRule();

  class  SchmContext : public antlr4::ParserRuleContext {
  public:
    SchmContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SchmContext* schm();

  class  SbwordiContext : public antlr4::ParserRuleContext {
  public:
    SbwordiContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> LET();
    antlr4::tree::TerminalNode* LET(size_t i);
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SbwordiContext* sbwordi();

  class  SbwordoContext : public antlr4::ParserRuleContext {
  public:
    SbwordoContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> LET();
    antlr4::tree::TerminalNode* LET(size_t i);
    std::vector<FunCallContext *> funCall();
    FunCallContext* funCall(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SbwordoContext* sbwordo();

  class  FunCallContext : public antlr4::ParserRuleContext {
  public:
    FunCallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    SbwordiContext *sbwordi();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunCallContext* funCall();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

