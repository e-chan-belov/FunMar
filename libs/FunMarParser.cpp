
// Generated from FunMar.g4 by ANTLR 4.13.2


#include "FunMarVisitor.h"

#include "FunMarParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct FunMarParserStaticData final {
  FunMarParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  FunMarParserStaticData(const FunMarParserStaticData&) = delete;
  FunMarParserStaticData(FunMarParserStaticData&&) = delete;
  FunMarParserStaticData& operator=(const FunMarParserStaticData&) = delete;
  FunMarParserStaticData& operator=(FunMarParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag funmarParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<FunMarParserStaticData> funmarParserStaticData = nullptr;

void funmarParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (funmarParserStaticData != nullptr) {
    return;
  }
#else
  assert(funmarParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<FunMarParserStaticData>(
    std::vector<std::string>{
      "prog", "func", "expStmt", "stmt", "funMarRule", "terminalRule", "schm", 
      "sbwordi", "sbwordo", "abst", "funcAbst"
    },
    std::vector<std::string>{
      "", "'{'", "'}'", "';'", "'->'", "'=>'", "'scheme'", "'('", "')'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "LET", "ID", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,11,102,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,1,0,4,0,24,8,0,11,0,12,0,25,1,0,1,0,1,
  	1,1,1,1,1,5,1,33,8,1,10,1,12,1,36,9,1,1,1,1,1,1,2,1,2,1,2,1,2,3,2,44,
  	8,2,1,3,1,3,3,3,48,8,3,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,6,1,6,1,6,5,
  	6,61,8,6,10,6,12,6,64,9,6,1,6,1,6,1,6,1,7,3,7,70,8,7,1,7,1,7,5,7,74,8,
  	7,10,7,12,7,77,9,7,1,7,3,7,80,8,7,1,8,4,8,83,8,8,11,8,12,8,84,1,9,1,9,
  	1,10,1,10,1,10,1,10,1,10,4,10,94,8,10,11,10,12,10,95,1,10,1,10,3,10,100,
  	8,10,1,10,0,0,11,0,2,4,6,8,10,12,14,16,18,20,0,1,1,0,9,10,102,0,23,1,
  	0,0,0,2,29,1,0,0,0,4,43,1,0,0,0,6,47,1,0,0,0,8,49,1,0,0,0,10,53,1,0,0,
  	0,12,57,1,0,0,0,14,69,1,0,0,0,16,82,1,0,0,0,18,86,1,0,0,0,20,99,1,0,0,
  	0,22,24,3,2,1,0,23,22,1,0,0,0,24,25,1,0,0,0,25,23,1,0,0,0,25,26,1,0,0,
  	0,26,27,1,0,0,0,27,28,5,0,0,1,28,1,1,0,0,0,29,30,5,10,0,0,30,34,5,1,0,
  	0,31,33,3,4,2,0,32,31,1,0,0,0,33,36,1,0,0,0,34,32,1,0,0,0,34,35,1,0,0,
  	0,35,37,1,0,0,0,36,34,1,0,0,0,37,38,5,2,0,0,38,3,1,0,0,0,39,40,3,6,3,
  	0,40,41,5,3,0,0,41,44,1,0,0,0,42,44,3,12,6,0,43,39,1,0,0,0,43,42,1,0,
  	0,0,44,5,1,0,0,0,45,48,3,8,4,0,46,48,3,10,5,0,47,45,1,0,0,0,47,46,1,0,
  	0,0,48,7,1,0,0,0,49,50,3,14,7,0,50,51,5,4,0,0,51,52,3,16,8,0,52,9,1,0,
  	0,0,53,54,3,14,7,0,54,55,5,5,0,0,55,56,3,16,8,0,56,11,1,0,0,0,57,58,5,
  	6,0,0,58,62,5,1,0,0,59,61,3,4,2,0,60,59,1,0,0,0,61,64,1,0,0,0,62,60,1,
  	0,0,0,62,63,1,0,0,0,63,65,1,0,0,0,64,62,1,0,0,0,65,66,5,2,0,0,66,67,5,
  	3,0,0,67,13,1,0,0,0,68,70,5,9,0,0,69,68,1,0,0,0,69,70,1,0,0,0,70,75,1,
  	0,0,0,71,72,5,10,0,0,72,74,5,9,0,0,73,71,1,0,0,0,74,77,1,0,0,0,75,73,
  	1,0,0,0,75,76,1,0,0,0,76,79,1,0,0,0,77,75,1,0,0,0,78,80,5,10,0,0,79,78,
  	1,0,0,0,79,80,1,0,0,0,80,15,1,0,0,0,81,83,3,20,10,0,82,81,1,0,0,0,83,
  	84,1,0,0,0,84,82,1,0,0,0,84,85,1,0,0,0,85,17,1,0,0,0,86,87,7,0,0,0,87,
  	19,1,0,0,0,88,100,5,9,0,0,89,100,5,10,0,0,90,91,5,10,0,0,91,93,5,7,0,
  	0,92,94,3,18,9,0,93,92,1,0,0,0,94,95,1,0,0,0,95,93,1,0,0,0,95,96,1,0,
  	0,0,96,97,1,0,0,0,97,98,5,8,0,0,98,100,1,0,0,0,99,88,1,0,0,0,99,89,1,
  	0,0,0,99,90,1,0,0,0,100,21,1,0,0,0,11,25,34,43,47,62,69,75,79,84,95,99
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  funmarParserStaticData = std::move(staticData);
}

}

FunMarParser::FunMarParser(TokenStream *input) : FunMarParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

FunMarParser::FunMarParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  FunMarParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *funmarParserStaticData->atn, funmarParserStaticData->decisionToDFA, funmarParserStaticData->sharedContextCache, options);
}

FunMarParser::~FunMarParser() {
  delete _interpreter;
}

const atn::ATN& FunMarParser::getATN() const {
  return *funmarParserStaticData->atn;
}

std::string FunMarParser::getGrammarFileName() const {
  return "FunMar.g4";
}

const std::vector<std::string>& FunMarParser::getRuleNames() const {
  return funmarParserStaticData->ruleNames;
}

const dfa::Vocabulary& FunMarParser::getVocabulary() const {
  return funmarParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView FunMarParser::getSerializedATN() const {
  return funmarParserStaticData->serializedATN;
}


//----------------- ProgContext ------------------------------------------------------------------

FunMarParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FunMarParser::ProgContext::EOF() {
  return getToken(FunMarParser::EOF, 0);
}

std::vector<FunMarParser::FuncContext *> FunMarParser::ProgContext::func() {
  return getRuleContexts<FunMarParser::FuncContext>();
}

FunMarParser::FuncContext* FunMarParser::ProgContext::func(size_t i) {
  return getRuleContext<FunMarParser::FuncContext>(i);
}


size_t FunMarParser::ProgContext::getRuleIndex() const {
  return FunMarParser::RuleProg;
}


std::any FunMarParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FunMarVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

FunMarParser::ProgContext* FunMarParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, FunMarParser::RuleProg);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(23); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(22);
      func();
      setState(25); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == FunMarParser::ID);
    setState(27);
    match(FunMarParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncContext ------------------------------------------------------------------

FunMarParser::FuncContext::FuncContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FunMarParser::FuncContext::ID() {
  return getToken(FunMarParser::ID, 0);
}

std::vector<FunMarParser::ExpStmtContext *> FunMarParser::FuncContext::expStmt() {
  return getRuleContexts<FunMarParser::ExpStmtContext>();
}

FunMarParser::ExpStmtContext* FunMarParser::FuncContext::expStmt(size_t i) {
  return getRuleContext<FunMarParser::ExpStmtContext>(i);
}


size_t FunMarParser::FuncContext::getRuleIndex() const {
  return FunMarParser::RuleFunc;
}


std::any FunMarParser::FuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FunMarVisitor*>(visitor))
    return parserVisitor->visitFunc(this);
  else
    return visitor->visitChildren(this);
}

FunMarParser::FuncContext* FunMarParser::func() {
  FuncContext *_localctx = _tracker.createInstance<FuncContext>(_ctx, getState());
  enterRule(_localctx, 2, FunMarParser::RuleFunc);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(29);
    match(FunMarParser::ID);
    setState(30);
    match(FunMarParser::T__0);
    setState(34);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1648) != 0)) {
      setState(31);
      expStmt();
      setState(36);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(37);
    match(FunMarParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpStmtContext ------------------------------------------------------------------

FunMarParser::ExpStmtContext::ExpStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FunMarParser::StmtContext* FunMarParser::ExpStmtContext::stmt() {
  return getRuleContext<FunMarParser::StmtContext>(0);
}

FunMarParser::SchmContext* FunMarParser::ExpStmtContext::schm() {
  return getRuleContext<FunMarParser::SchmContext>(0);
}


size_t FunMarParser::ExpStmtContext::getRuleIndex() const {
  return FunMarParser::RuleExpStmt;
}


std::any FunMarParser::ExpStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FunMarVisitor*>(visitor))
    return parserVisitor->visitExpStmt(this);
  else
    return visitor->visitChildren(this);
}

FunMarParser::ExpStmtContext* FunMarParser::expStmt() {
  ExpStmtContext *_localctx = _tracker.createInstance<ExpStmtContext>(_ctx, getState());
  enterRule(_localctx, 4, FunMarParser::RuleExpStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(43);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FunMarParser::T__3:
      case FunMarParser::T__4:
      case FunMarParser::LET:
      case FunMarParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(39);
        stmt();
        setState(40);
        match(FunMarParser::T__2);
        break;
      }

      case FunMarParser::T__5: {
        enterOuterAlt(_localctx, 2);
        setState(42);
        schm();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

FunMarParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FunMarParser::FunMarRuleContext* FunMarParser::StmtContext::funMarRule() {
  return getRuleContext<FunMarParser::FunMarRuleContext>(0);
}

FunMarParser::TerminalRuleContext* FunMarParser::StmtContext::terminalRule() {
  return getRuleContext<FunMarParser::TerminalRuleContext>(0);
}


size_t FunMarParser::StmtContext::getRuleIndex() const {
  return FunMarParser::RuleStmt;
}


std::any FunMarParser::StmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FunMarVisitor*>(visitor))
    return parserVisitor->visitStmt(this);
  else
    return visitor->visitChildren(this);
}

FunMarParser::StmtContext* FunMarParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 6, FunMarParser::RuleStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(47);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(45);
      funMarRule();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(46);
      terminalRule();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunMarRuleContext ------------------------------------------------------------------

FunMarParser::FunMarRuleContext::FunMarRuleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FunMarParser::SbwordiContext* FunMarParser::FunMarRuleContext::sbwordi() {
  return getRuleContext<FunMarParser::SbwordiContext>(0);
}

FunMarParser::SbwordoContext* FunMarParser::FunMarRuleContext::sbwordo() {
  return getRuleContext<FunMarParser::SbwordoContext>(0);
}


size_t FunMarParser::FunMarRuleContext::getRuleIndex() const {
  return FunMarParser::RuleFunMarRule;
}


std::any FunMarParser::FunMarRuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FunMarVisitor*>(visitor))
    return parserVisitor->visitFunMarRule(this);
  else
    return visitor->visitChildren(this);
}

FunMarParser::FunMarRuleContext* FunMarParser::funMarRule() {
  FunMarRuleContext *_localctx = _tracker.createInstance<FunMarRuleContext>(_ctx, getState());
  enterRule(_localctx, 8, FunMarParser::RuleFunMarRule);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(49);
    sbwordi();
    setState(50);
    match(FunMarParser::T__3);
    setState(51);
    sbwordo();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TerminalRuleContext ------------------------------------------------------------------

FunMarParser::TerminalRuleContext::TerminalRuleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FunMarParser::SbwordiContext* FunMarParser::TerminalRuleContext::sbwordi() {
  return getRuleContext<FunMarParser::SbwordiContext>(0);
}

FunMarParser::SbwordoContext* FunMarParser::TerminalRuleContext::sbwordo() {
  return getRuleContext<FunMarParser::SbwordoContext>(0);
}


size_t FunMarParser::TerminalRuleContext::getRuleIndex() const {
  return FunMarParser::RuleTerminalRule;
}


std::any FunMarParser::TerminalRuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FunMarVisitor*>(visitor))
    return parserVisitor->visitTerminalRule(this);
  else
    return visitor->visitChildren(this);
}

FunMarParser::TerminalRuleContext* FunMarParser::terminalRule() {
  TerminalRuleContext *_localctx = _tracker.createInstance<TerminalRuleContext>(_ctx, getState());
  enterRule(_localctx, 10, FunMarParser::RuleTerminalRule);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(53);
    sbwordi();
    setState(54);
    match(FunMarParser::T__4);
    setState(55);
    sbwordo();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SchmContext ------------------------------------------------------------------

FunMarParser::SchmContext::SchmContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FunMarParser::ExpStmtContext *> FunMarParser::SchmContext::expStmt() {
  return getRuleContexts<FunMarParser::ExpStmtContext>();
}

FunMarParser::ExpStmtContext* FunMarParser::SchmContext::expStmt(size_t i) {
  return getRuleContext<FunMarParser::ExpStmtContext>(i);
}


size_t FunMarParser::SchmContext::getRuleIndex() const {
  return FunMarParser::RuleSchm;
}


std::any FunMarParser::SchmContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FunMarVisitor*>(visitor))
    return parserVisitor->visitSchm(this);
  else
    return visitor->visitChildren(this);
}

FunMarParser::SchmContext* FunMarParser::schm() {
  SchmContext *_localctx = _tracker.createInstance<SchmContext>(_ctx, getState());
  enterRule(_localctx, 12, FunMarParser::RuleSchm);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(57);
    match(FunMarParser::T__5);
    setState(58);
    match(FunMarParser::T__0);
    setState(62);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1648) != 0)) {
      setState(59);
      expStmt();
      setState(64);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(65);
    match(FunMarParser::T__1);
    setState(66);
    match(FunMarParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SbwordiContext ------------------------------------------------------------------

FunMarParser::SbwordiContext::SbwordiContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> FunMarParser::SbwordiContext::LET() {
  return getTokens(FunMarParser::LET);
}

tree::TerminalNode* FunMarParser::SbwordiContext::LET(size_t i) {
  return getToken(FunMarParser::LET, i);
}

std::vector<tree::TerminalNode *> FunMarParser::SbwordiContext::ID() {
  return getTokens(FunMarParser::ID);
}

tree::TerminalNode* FunMarParser::SbwordiContext::ID(size_t i) {
  return getToken(FunMarParser::ID, i);
}


size_t FunMarParser::SbwordiContext::getRuleIndex() const {
  return FunMarParser::RuleSbwordi;
}


std::any FunMarParser::SbwordiContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FunMarVisitor*>(visitor))
    return parserVisitor->visitSbwordi(this);
  else
    return visitor->visitChildren(this);
}

FunMarParser::SbwordiContext* FunMarParser::sbwordi() {
  SbwordiContext *_localctx = _tracker.createInstance<SbwordiContext>(_ctx, getState());
  enterRule(_localctx, 14, FunMarParser::RuleSbwordi);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(69);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FunMarParser::LET) {
      setState(68);
      match(FunMarParser::LET);
    }
    setState(75);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(71);
        match(FunMarParser::ID);
        setState(72);
        match(FunMarParser::LET); 
      }
      setState(77);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    }
    setState(79);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FunMarParser::ID) {
      setState(78);
      match(FunMarParser::ID);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SbwordoContext ------------------------------------------------------------------

FunMarParser::SbwordoContext::SbwordoContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FunMarParser::FuncAbstContext *> FunMarParser::SbwordoContext::funcAbst() {
  return getRuleContexts<FunMarParser::FuncAbstContext>();
}

FunMarParser::FuncAbstContext* FunMarParser::SbwordoContext::funcAbst(size_t i) {
  return getRuleContext<FunMarParser::FuncAbstContext>(i);
}


size_t FunMarParser::SbwordoContext::getRuleIndex() const {
  return FunMarParser::RuleSbwordo;
}


std::any FunMarParser::SbwordoContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FunMarVisitor*>(visitor))
    return parserVisitor->visitSbwordo(this);
  else
    return visitor->visitChildren(this);
}

FunMarParser::SbwordoContext* FunMarParser::sbwordo() {
  SbwordoContext *_localctx = _tracker.createInstance<SbwordoContext>(_ctx, getState());
  enterRule(_localctx, 16, FunMarParser::RuleSbwordo);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(82); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(81);
      funcAbst();
      setState(84); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == FunMarParser::LET

    || _la == FunMarParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AbstContext ------------------------------------------------------------------

FunMarParser::AbstContext::AbstContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FunMarParser::AbstContext::LET() {
  return getToken(FunMarParser::LET, 0);
}

tree::TerminalNode* FunMarParser::AbstContext::ID() {
  return getToken(FunMarParser::ID, 0);
}


size_t FunMarParser::AbstContext::getRuleIndex() const {
  return FunMarParser::RuleAbst;
}


std::any FunMarParser::AbstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FunMarVisitor*>(visitor))
    return parserVisitor->visitAbst(this);
  else
    return visitor->visitChildren(this);
}

FunMarParser::AbstContext* FunMarParser::abst() {
  AbstContext *_localctx = _tracker.createInstance<AbstContext>(_ctx, getState());
  enterRule(_localctx, 18, FunMarParser::RuleAbst);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(86);
    _la = _input->LA(1);
    if (!(_la == FunMarParser::LET

    || _la == FunMarParser::ID)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncAbstContext ------------------------------------------------------------------

FunMarParser::FuncAbstContext::FuncAbstContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FunMarParser::FuncAbstContext::LET() {
  return getToken(FunMarParser::LET, 0);
}

tree::TerminalNode* FunMarParser::FuncAbstContext::ID() {
  return getToken(FunMarParser::ID, 0);
}

std::vector<FunMarParser::AbstContext *> FunMarParser::FuncAbstContext::abst() {
  return getRuleContexts<FunMarParser::AbstContext>();
}

FunMarParser::AbstContext* FunMarParser::FuncAbstContext::abst(size_t i) {
  return getRuleContext<FunMarParser::AbstContext>(i);
}


size_t FunMarParser::FuncAbstContext::getRuleIndex() const {
  return FunMarParser::RuleFuncAbst;
}


std::any FunMarParser::FuncAbstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FunMarVisitor*>(visitor))
    return parserVisitor->visitFuncAbst(this);
  else
    return visitor->visitChildren(this);
}

FunMarParser::FuncAbstContext* FunMarParser::funcAbst() {
  FuncAbstContext *_localctx = _tracker.createInstance<FuncAbstContext>(_ctx, getState());
  enterRule(_localctx, 20, FunMarParser::RuleFuncAbst);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(99);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(88);
      match(FunMarParser::LET);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(89);
      match(FunMarParser::ID);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(90);
      match(FunMarParser::ID);
      setState(91);
      match(FunMarParser::T__6);
      setState(93); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(92);
        abst();
        setState(95); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == FunMarParser::LET

      || _la == FunMarParser::ID);
      setState(97);
      match(FunMarParser::T__7);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void FunMarParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  funmarParserInitialize();
#else
  ::antlr4::internal::call_once(funmarParserOnceFlag, funmarParserInitialize);
#endif
}
