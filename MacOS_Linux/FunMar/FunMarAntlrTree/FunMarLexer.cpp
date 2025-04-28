
// Generated from FunMar.g4 by ANTLR 4.13.2


#include "FunMarLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct FunMarLexerStaticData final {
  FunMarLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  FunMarLexerStaticData(const FunMarLexerStaticData&) = delete;
  FunMarLexerStaticData(FunMarLexerStaticData&&) = delete;
  FunMarLexerStaticData& operator=(const FunMarLexerStaticData&) = delete;
  FunMarLexerStaticData& operator=(FunMarLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag funmarlexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<FunMarLexerStaticData> funmarlexerLexerStaticData = nullptr;

void funmarlexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (funmarlexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(funmarlexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<FunMarLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "LET", 
      "ID", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'{'", "'}'", "';'", "'->'", "'=>'", "'scheme'", "'('", "')'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "LET", "ID", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,11,69,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,1,0,1,0,1,1,1,1,1,2,1,2,1,3,1,3,1,
  	3,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,7,1,7,1,8,1,8,5,8,
  	49,8,8,10,8,12,8,52,9,8,1,8,1,8,1,9,1,9,5,9,58,8,9,10,9,12,9,61,9,9,1,
  	10,4,10,64,8,10,11,10,12,10,65,1,10,1,10,1,50,0,11,1,1,3,2,5,3,7,4,9,
  	5,11,6,13,7,15,8,17,9,19,10,21,11,1,0,3,3,0,65,90,95,95,97,122,4,0,48,
  	57,65,90,95,95,97,122,3,0,9,10,13,13,32,32,71,0,1,1,0,0,0,0,3,1,0,0,0,
  	0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,
  	0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,1,23,1,0,0,0,3,25,1,0,0,
  	0,5,27,1,0,0,0,7,29,1,0,0,0,9,32,1,0,0,0,11,35,1,0,0,0,13,42,1,0,0,0,
  	15,44,1,0,0,0,17,46,1,0,0,0,19,55,1,0,0,0,21,63,1,0,0,0,23,24,5,123,0,
  	0,24,2,1,0,0,0,25,26,5,125,0,0,26,4,1,0,0,0,27,28,5,59,0,0,28,6,1,0,0,
  	0,29,30,5,45,0,0,30,31,5,62,0,0,31,8,1,0,0,0,32,33,5,61,0,0,33,34,5,62,
  	0,0,34,10,1,0,0,0,35,36,5,115,0,0,36,37,5,99,0,0,37,38,5,104,0,0,38,39,
  	5,101,0,0,39,40,5,109,0,0,40,41,5,101,0,0,41,12,1,0,0,0,42,43,5,40,0,
  	0,43,14,1,0,0,0,44,45,5,41,0,0,45,16,1,0,0,0,46,50,5,34,0,0,47,49,9,0,
  	0,0,48,47,1,0,0,0,49,52,1,0,0,0,50,51,1,0,0,0,50,48,1,0,0,0,51,53,1,0,
  	0,0,52,50,1,0,0,0,53,54,5,34,0,0,54,18,1,0,0,0,55,59,7,0,0,0,56,58,7,
  	1,0,0,57,56,1,0,0,0,58,61,1,0,0,0,59,57,1,0,0,0,59,60,1,0,0,0,60,20,1,
  	0,0,0,61,59,1,0,0,0,62,64,7,2,0,0,63,62,1,0,0,0,64,65,1,0,0,0,65,63,1,
  	0,0,0,65,66,1,0,0,0,66,67,1,0,0,0,67,68,6,10,0,0,68,22,1,0,0,0,4,0,50,
  	59,65,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  funmarlexerLexerStaticData = std::move(staticData);
}

}

FunMarLexer::FunMarLexer(CharStream *input) : Lexer(input) {
  FunMarLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *funmarlexerLexerStaticData->atn, funmarlexerLexerStaticData->decisionToDFA, funmarlexerLexerStaticData->sharedContextCache);
}

FunMarLexer::~FunMarLexer() {
  delete _interpreter;
}

std::string FunMarLexer::getGrammarFileName() const {
  return "FunMar.g4";
}

const std::vector<std::string>& FunMarLexer::getRuleNames() const {
  return funmarlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& FunMarLexer::getChannelNames() const {
  return funmarlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& FunMarLexer::getModeNames() const {
  return funmarlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& FunMarLexer::getVocabulary() const {
  return funmarlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView FunMarLexer::getSerializedATN() const {
  return funmarlexerLexerStaticData->serializedATN;
}

const atn::ATN& FunMarLexer::getATN() const {
  return *funmarlexerLexerStaticData->atn;
}




void FunMarLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  funmarlexerLexerInitialize();
#else
  ::antlr4::internal::call_once(funmarlexerLexerOnceFlag, funmarlexerLexerInitialize);
#endif
}
