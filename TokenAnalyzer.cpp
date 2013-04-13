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

TokenAnalyzer::TokenAnalyzer(Vector<Token>& inputTokens) {
    tokens = inputTokens;
}

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

void TokenAnalyzer::showDebugInformation(bool toShow) {
    showDebug = toShow;
}

string TokenAnalyzer::stringToLower(string str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}

int TokenAnalyzer::getSyllableCount(string word) {
    word = stringToLower(word);
    int numSyllables = 0;
    for (int i = 0; i < word.length(); i++) {
        if (isVowel(word[i])) {
            numSyllables++;
        }
        
        // Exclude vowels that have vowels directly before them.
        if (isVowel(word[i]) && i > 0 && isVowel(word[i - 1])) {
            numSyllables--;
        }
    }

    // Exclude the letter e, if it appears by itself at the end of a word.
    if (word[word.length() - 1] == 'e') {
        numSyllables--;
    }
    return numSyllables;
}

void TokenAnalyzer::preProcessTokens() {
    string currentStr;
    TokenType currentType;
    for (int i = 0; i < tokens.size(); i++) {
        currentType = tokens.get(i).tokenType;
        currentStr = tokens.get(i).tokenVal;
        
        switch (currentType) {
            case OPERATOR:
                // detect contractions and fix by merging into one token
                if (i > 0 && tokens.get(i).tokenVal == "'" &&
                    tokens.get(i - 1).tokenType == WORD &&
                    tokens.get(i + 1).tokenType == WORD) {
                    Token mergedToken;
                    mergedToken.tokenType = WORD;
                    mergedToken.tokenVal = tokens.get(i - 1).tokenVal +
                                           tokens.get(i).tokenVal +
                                           tokens.get(i + 1).tokenVal;
                    if (showDebug) {
                        cout << "Token: [" << currentStr << "] " << endl;
                        cout << "New Token: [" << mergedToken.tokenVal << "]"
                         << endl;
                    }
                    
                    tokens.set(i - 1, mergedToken);
                    tokens.remove(i);
                    
                    // remove i twice since removing the first i bumps down i
                    tokens.remove(i);
                }
                break;
        }
    }
}

void TokenAnalyzer::analyzeTokens() {
    preProcessTokens();
    //    int nSyllables;
    //    string previousStr;
    //    char lastCharRead;
    //    int nextCharToRead;
    
    int nSyllables;
    string currentStr;
    TokenType currentType;
    for (int i = 0; i < tokens.size(); i++) {
        currentType = tokens.get(i).tokenType;
        currentStr = tokens.get(i).tokenVal;
        switch (currentType) {
            case WORD:
                textSummary.numWords++;
                nSyllables = getSyllableCount(currentStr);
                if (showDebug) {
                    cout << "Token: [" << currentStr << "] (word; " <<
                    nSyllables << " syllable)" << endl;
                }
                textSummary.numSyllables += nSyllables;
                break;
            case OPERATOR:
                if (showDebug) {
                    cout << "Token: [" << currentStr << "] (end of sentence)"
                    << endl;
                }
                textSummary.numSentences++;
                break;
            case SEPARATOR:
                break;
            case NUMBER:
            case STRING:
                break;
        }
    }
    
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

     }
     */
    
    //        previousStr = currentStr;
}