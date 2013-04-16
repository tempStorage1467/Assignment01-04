/*
 * File: TokenAnalyzer.cpp
 * ----------------------
 * Name: Eric Beach
 * Section: SCPD, Aaron Broder <abroder@stanford.edu>
 * Copyright 2013 Eric Beach <ebeach@google.com>
 * Assignment 1 - Pt. 4 - Flesch-Kincaid
 * This file implements a class that analyzes tokens to compute grade
 *   level complexity.
 *
 * This file lightly linted using
 * http://google-styleguide.googlecode.com/svn/trunk/cpplint/cpplint.py
 */

#include <string>
#include "TokenAnalyzer.h"

/*
 * Constructor to receive tokens and subsequently perform analysis.
 */
TokenAnalyzer::TokenAnalyzer(Vector<Token>& inputTokens) {
    tokens = inputTokens;
}

/*
 * Compute the grade level of the analyzed text.
 */
double TokenAnalyzer::getGradeLevel() {

    // As a minor edge case, if a file doesn't appear to have any words
    //   or sentences in it, you can just pretend that it contains a single
    //   word and a single sentence (which prevents a division by zero error
    //   when evaluating the above formula).
    if (textSummary.numWords == 0) {
        textSummary.numWords = 1;
    }
    if (textSummary.numSentences == 0) {
        textSummary.numSentences = 1;
    }
    double c1Val = double(textSummary.numWords)/
                     double(textSummary.numSentences);
    double c2Val = double(textSummary.numSyllables)/
                     double(textSummary.numWords);
    return -15.59 + ((0.39) * c1Val)
                  + ((11.8) * c2Val);
}

/*
 * Obtain the analyzed and computed summary of the text.
 */
TextAnalysisSummary TokenAnalyzer::getTextAnalysisSummary() {
    analyzeTokens();
    textSummary.gradeLevel = getGradeLevel();
    return textSummary;
}

/*
 * Determine whether a character is a vowel for purposes of this test.
 */
bool TokenAnalyzer::isVowel(char letter) {
    if (letter == 'a' || letter == 'e' || letter == 'i' ||
        letter == 'o' || letter == 'u' || letter == 'y' ||
        letter == 'A' || letter == 'E' || letter == 'I' ||
        letter == 'O' || letter == 'U' || letter == 'Y') {
        return true;
    } else {
        return false;
    }
}

/*
 * Show debugging information as the text is being parsed into tokens.
 */
void TokenAnalyzer::showDebugInformation(bool toShow) {
    showDebug = toShow;
}

/*
 * Convert a string to all lowercase.
 */
string TokenAnalyzer::stringToLower(string str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}

/*
 * Compute the number of syllables in a word.
 */
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
    
    // Notice that under this definition, the word “me” would have zero
    //   syllables in it, since the final “e” doesn't contribute to
    //   the total. To address this, you should assume that all words
    //   have at least one syllable in them.
    if (numSyllables == 0) {
        numSyllables = 1;
    }
    return numSyllables;
}

/*
 * Perform processing on tokens before they are analyzed for words, sentences,
 *   etc. This is necessary to turn phrases such as "isn't" from three
 *   tokens into one.
 */
void TokenAnalyzer::preProcessTokens() {
    string currentStr;
    TokenType currentType;
    for (int i = 0; i < tokens.size(); i++) {
        currentType = tokens.get(i).tokenType;
        currentStr = tokens.get(i).tokenVal;
        
        // "To determine what counts as a word, you can assume that
        //   any token that starts with a letter counts as a word, so apple
        //   and A-1 would both be considered words."
        //
        //  I chose to implement my word counting such that 'Hello' counts as
        //   one word since: (a) this is more intelligent (b) this technically
        //   meets the requirements in that it still counts as a word
        //   any token that starts with a letter... it just does more than
        //   that.
        
        switch (currentType) {
            case OPERATOR:
                // detect contractions and fix by merging into one token
                // need to catch "isn't" but not "me. 'Hello now.'"
                if (i > 0 && tokens.get(i).tokenVal == "'" &&
                    tokens.get(i - 1).tokenType == WORD &&
                    tokens.get(i + 1).tokenType == WORD &&
                    tokens.get(i + 1).tokenVal.length() == 1) {
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
    if (showDebug) {
        cout << "-- End Pre-Process --" << endl;
    }
}

/*
 * Analyze tokens to compute the number of sentences, syllables, etc.
 */
void TokenAnalyzer::analyzeTokens() {
    preProcessTokens();

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
            case SEPARATOR:
                // As an approximation of the number of sentences,
                //   you can just count up the number of punctuation
                //   symbols that appear at the ends of sentences
                //   (namely, periods, exclamation points, and question
                //   marks).
                if (currentStr == "," || currentStr == "'") {
                    if (showDebug) {
                        cout << "Token: [" << currentStr << "]" << endl;
                        continue;
                    }
                }

                if (currentStr == "." || currentStr == "!" ||
                    currentStr == "?") {
                    if (showDebug) {
                        cout << "Token: [" << currentStr << "] "
                             << "(end of sentence)" << endl;
                    }
                    textSummary.numSentences++;
                }
                break;
            case NUMBER:
            case STRING:
                cout << "Other Thing: " << currentStr;
                break;
        }
    }
}
