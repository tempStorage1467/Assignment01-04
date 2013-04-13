/*
 * File: TextParser.cpp
 * ----------------------
 * Name: Eric Beach
 * Section: [TODO: enter section leader here]
 * Copyright 2013 <Eric Beach>
 * This file implements a class that takes in a file or string and
 *   parses it with a tokenizer and analyzes the complexity of the writing.
 * [TODO: rewrite the documentation]
 *
 * This file lightly linted using
 * http://google-styleguide.googlecode.com/svn/trunk/cpplint/cpplint.py
 */

#include "TextParser.h"
#include <iostream>
using namespace std;

TextParser::TextParser(string strInput) {
    tokenizer = TokenScanner(strInput);
}

TextParser::TextParser(istream& fileInput) {
    tokenizer = TokenScanner(fileInput);
}

void TextParser::showDebugInformation(bool toDebug) {
    showDebug = toDebug;
}

TextAnalysisSummary TextParser::getTextAnalysisSummary() {
    return textSummary;
}

bool TextParser::isVowel(char letter) {
    if (letter == 'a' || letter == 'e' || letter == 'i' ||
        letter == 'o' || letter == 'u' || letter == 'y') {
        return true;
    } else {
        return false;
    }
}

int TextParser::getSyllableCount(string word) {
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
}

void TextParser::processInput() {
    tokenizer.ignoreWhitespace();
    
    string currentStr;
    string previousStr;
    char lastCharRead;
    int nextCharToRead;
    TokenType type;
    int nSyllables;
    while (tokenizer.hasMoreTokens()) {
        currentStr = tokenizer.nextToken();
        type = tokenizer.getTokenType(currentStr);
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
        
        if (showDebug) {
            cout << currentStr << " is type " << type << endl;
        }
        previousStr = currentStr;
        textSummary.numTokens++;
    }
}