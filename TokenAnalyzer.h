//
//  TokenAnalyzer.h
//  Flesch-Kincaid
//
//  Created by Eric Beach on 4/13/13.
//
//

#ifndef __Flesch_Kincaid__TokenAnalyzer__
#define __Flesch_Kincaid__TokenAnalyzer__

#include <iostream>
#include "TextParser.h"

struct TextAnalysisSummary {
    unsigned int numWords = 0;
    unsigned int numSentences = 0;
    unsigned int numSyllables = 0;
    unsigned int numTokens = 0;
};

class TokenAnalyzer {
private:
    Vector<Token> tokens;
    TextAnalysisSummary textSummary;
    int getSyllableCount(string word);
    bool isVowel(char letter);
    void analyzeTokens();
public:
    TokenAnalyzer(Vector<Token> inputTokens);
    TextAnalysisSummary getTextAnalysisSummary();
};

#endif /* defined(__Flesch_Kincaid__TokenAnalyzer__) */
