/*
 * File: TokenAnalyzer.h
 * ----------------------
 * Name: Eric Beach
 * Section: SCPD, Aaron Broder <abroder@stanford.edu>
 * Copyright 2013 Eric Beach <ebeach@google.com>
 * Assignment 1 - Pt. 4 - Flesch-Kincaid
 * This file defines a class for analyzing a vector of tokens to compute
 *   the grade level.
 *
 * This file lightly linted using
 * http://google-styleguide.googlecode.com/svn/trunk/cpplint/cpplint.py
 */

#ifndef TOKENANALYZER_H_
#define TOKENANALYZER_H_

#include <iostream>
#include <string>
#include "TextParser.h"

/*
 * A structure to encapsulate the computed analysis of a stream of tokens
 *   that represents a text.
 */
struct TextAnalysisSummary {
    int numWords = 0;
    int numSentences = 0;
    int numSyllables = 0;
    double gradeLevel = 0;
};

/*
 * A class to analyze tokens.
 */
class TokenAnalyzer {
 private:
    // store of tokens read in from a file
    Vector<Token> tokens;

    // structure to encapsulate analysis of text
    TextAnalysisSummary textSummary;

    // show debug information as analysis is done
    bool showDebug = true;

    // compute the number of syllables in a word
    int getSyllableCount(string word);

    // determine whether a character is a vowel for the formula
    bool isVowel(char letter);

    // analyze tokens for number of words, sentences, syllables, etc.
    void analyzeTokens();

    // perform processing on tokens before analysis
    void preProcessTokens();

    // convert a string to lowercase
    string stringToLower(string str);

    // get the grade level of the text
    double getGradeLevel();

 public:
    // Constructor to receive tokens
    TokenAnalyzer(Vector<Token>& inputTokens);

    // get the summary analysis of the text
    TextAnalysisSummary getTextAnalysisSummary();

    // show the debug information as analysis occurs
    void showDebugInformation(bool toShow);
};

#endif  // TOKENANALYZER_H_
