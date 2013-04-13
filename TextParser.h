/*
 * File: TextParser.h
 * ----------------------
 * Name: Eric Beach
 * Section: [TODO: enter section leader here]
 * Copyright 2013 <Eric Beach>
 * This file defines a class that takes in a file or string and
 *   parses it with a tokenizer and analyzes the complexity of the writing.
 * [TODO: rewrite the documentation]
 *
 * This file lightly linted using
 * http://google-styleguide.googlecode.com/svn/trunk/cpplint/cpplint.py
 */

#ifndef __Flesch_Kincaid__TextParser__
#define __Flesch_Kincaid__TextParser__

#include <iostream>
#include "tokenscanner.h"
#include "vector.h"

using namespace std;

struct Token {
    string tokenVal;
    TokenType tokenType;
};

struct TextAnalysisSummary {
    unsigned int numWords = 0;
    unsigned int numSentences = 0;
    unsigned int numSyllables = 0;
    unsigned int numTokens = 0;
};

class TextParser {
 private:
    bool showDebug = false;
    TextAnalysisSummary textSummary;
    TokenScanner tokenizer;
    int getSyllableCount(string word);
    bool isVowel(char letter);
    Vector<Token> tokens;

 public:
    TextParser(istream& fileStream);
    TextParser(string input);
    void showDebugInformation(bool toShow);
    void processInput();
    TextAnalysisSummary getTextAnalysisSummary();
    
};

#endif /* defined(__Flesch_Kincaid__TextParser__) */
