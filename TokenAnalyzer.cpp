/*
 * File: TokenAnalyzer.cpp
 * ----------------------
 * Name: Eric Beach
 * Section: [TODO: enter section leader here]
 * Copyright 2013 <Eric Beach>
 * This file implements a class that analyzes tokens to compute grade
 *   level complexity.
 * [TODO: rewrite the documentation]
 *
 * This file lightly linted using
 * http://google-styleguide.googlecode.com/svn/trunk/cpplint/cpplint.py
 */

#include "TokenAnalyzer.h"

TextAnalysisSummary TokenAnalyzer::getTextAnalysisSummary() {
    analyzeTokens();
    return textSummary;
}

bool TokenAnalyzer::isVowel(char letter) {
    if (letter == 'a' || letter == 'e' || letter == 'i' ||
        letter == 'o' || letter == 'u' || letter == 'y') {
        return true;
    } else {
        return false;
    }
}

int TokenAnalyzer::getSyllableCount(string word) {
    // TODO: convert word to lower case
    int numSyllables = 0;
    for (int i = 0; i < word.length(); i++) {
        if (isVowel(word[i]) && i > 0 && !isVowel(word[i - 1])) {
            numSyllables--;
        }
    }
    
    if (word[word.length() - 1] == 'e') {
        numSyllables--;
    }
    return numSyllables;
}

void TokenAnalyzer::analyzeTokens() {
    //    int nSyllables;
    //    string previousStr;
    //    char lastCharRead;
    //    int nextCharToRead;
    
    /*
     switch (type) {
     case SEPARATOR:
     lastCharRead = previousStr[previousStr.length() - 1];
     nextCharToRead = tokenizer.getChar();
     if (lastCharRead < 46) {
     textSummary.numSentences++;
     }
     tokenizer.ungetChar(nextCharToRead);
     break;
     case WORD:
     textSummary.numWords++;
     nSyllables = getSyllableCount(currentStr);
     if (showDebug) {
     cout << "Token: [" << currentStr << "] (word; " <<
     nSyllables << " syllable)" << endl;
     }
     textSummary.numSyllables += nSyllables;
     break;
     case NUMBER:
     case STRING:
     case OPERATOR:
     if (showDebug) {
     cout << "Token: [" << currentStr << "] (end of sentence)" <<
     endl;
     }
     textSummary.numSentences++;
     break;
     }
     */
    
    //        previousStr = currentStr;
    //        textSummary.numTokens++;
}