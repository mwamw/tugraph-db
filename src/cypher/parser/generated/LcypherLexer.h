
// Generated from /home2/xcj/tugraph-2024-04-11/tugraph-db-master/src/cypher/grammar/../../..//src/cypher/grammar/Lcypher.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"


namespace parser {


class  LcypherLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, T__23 = 24, T__24 = 25, T__25 = 26, 
    T__26 = 27, T__27 = 28, T__28 = 29, T__29 = 30, T__30 = 31, T__31 = 32, 
    T__32 = 33, T__33 = 34, T__34 = 35, T__35 = 36, T__36 = 37, T__37 = 38, 
    T__38 = 39, T__39 = 40, T__40 = 41, T__41 = 42, T__42 = 43, T__43 = 44, 
    T__44 = 45, EXPLAIN = 46, PROFILE = 47, OPTIMIZE = 48, MAINTENANCE = 49, 
    VIEW = 50, UNION = 51, ALL = 52, OPTIONAL_ = 53, MATCH = 54, UNWIND = 55, 
    AS = 56, MERGE = 57, ON = 58, CREATE = 59, SET = 60, DETACH = 61, DELETE_ = 62, 
    REMOVE = 63, CALL = 64, YIELD = 65, WITH = 66, DISTINCT = 67, RETURN = 68, 
    ORDER = 69, BY = 70, L_SKIP = 71, LIMIT = 72, ASCENDING = 73, ASC = 74, 
    DESCENDING = 75, DESC = 76, USING = 77, JOIN = 78, START = 79, WHERE = 80, 
    NO_DUPLICATE_EDGE = 81, OR = 82, XOR = 83, AND = 84, NOT = 85, IN = 86, 
    STARTS = 87, ENDS = 88, CONTAINS = 89, REGEXP = 90, IS = 91, NULL_ = 92, 
    COUNT = 93, ANY = 94, NONE = 95, SINGLE = 96, TRUE_ = 97, FALSE_ = 98, 
    EXISTS = 99, CASE = 100, ELSE = 101, END = 102, WHEN = 103, THEN = 104, 
    StringLiteral = 105, EscapedChar = 106, HexInteger = 107, DecimalInteger = 108, 
    OctalInteger = 109, HexLetter = 110, HexDigit = 111, Digit = 112, NonZeroDigit = 113, 
    NonZeroOctDigit = 114, OctDigit = 115, ZeroDigit = 116, ExponentDecimalReal = 117, 
    RegularDecimalReal = 118, FILTER = 119, EXTRACT = 120, UnescapedSymbolicName = 121, 
    CONSTRAINT = 122, DO = 123, FOR = 124, REQUIRE = 125, UNIQUE = 126, 
    MANDATORY = 127, SCALAR = 128, OF = 129, ADD = 130, DROP = 131, IdentifierStart = 132, 
    IdentifierPart = 133, EscapedSymbolicName = 134, SP = 135, WHITESPACE = 136, 
    Comment = 137
  };

  explicit LcypherLexer(antlr4::CharStream *input);

  ~LcypherLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

}  // namespace parser
