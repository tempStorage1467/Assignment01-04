/*
 * File: FleschKincaid.cpp
 * ----------------------
 * Name: Eric Beach
 * Section: SCPD, Aaron Broder <abroder@stanford.edu>
 * Copyright 2013 Eric Beach <ebeach@google.com>
 * Assignment 1 - Pt. 4 - Flesch-Kincaid
 * This file is the starter project for the Flesch-Kincaid problem.
 *  It asks about debug information, prompts for file name, and outputs
 *  an analysis of the text.
 *
 * This file lightly linted using
 * http://google-styleguide.googlecode.com/svn/trunk/cpplint/cpplint.py
 */

#include <string>
#include <iostream>
#include "console.h"
#include "simpio.h"
#include "filelib.h"
#include "TextParser.h"
#include "TokenAnalyzer.h"
#include "TokenAnalyzerTest.h"

using namespace std;

/*
 * Ask the user whether to show debug information.
 */
bool showDebugInformation() {
    string toDebug = getLine("Show debugging information? (Y or N) ");
    while (toDebug != "Y" && toDebug != "y" &&
           toDebug != "N" && toDebug != "n") {
        cout << "Please enter Y or N." << endl;
        toDebug = getLine("Show debugging information? (Y or N) ");
    }
    return (toDebug == "y" || toDebug == "Y");
}

/*
 * Prompt the user for a file and read it into a stream.
 */
string getFile(ifstream& stream) {
    return promptUserForFile(stream, "Please enter a file to analyze: ");
}

/*
 * Run unit tests on parsing and analyzing texts.
 */
void runTests() {
    TokenAnalyzerTest test = TokenAnalyzerTest();
    test.runTests();
}

/*
 * Run unit tests, prompt the user for whether to debug, and the file
 *  to read. Analyze the file and output it to the user.
 */
int main() {
    // run tests
    runTests();

    // prompt user for whether to show debug information
    const bool SHOW_DEBUG_INFO = showDebugInformation();

    // read file
    //   prompt user for file name; keep prompting until valid file name
    //   Modify an istream passed in by reference
    ifstream fileStream;
    string fileName = getFile(fileStream);

    // convert ifstream to istream for use by tokenizer
    istream& stream = fileStream;

    // tokenize file
    //   accept istream and read the stream into a vector of tokens
    TextParser parser = TextParser(stream);
    parser.processInput();
    Vector<Token> tokens = parser.getTokens();

    // analyze text based upon a vector of tokens
    //     count up words, sentences, etc.
    //   store constants; return getGradeLevel()
    TokenAnalyzer analyzer = TokenAnalyzer(tokens);
    analyzer.showDebugInformation(SHOW_DEBUG_INFO);
    TextAnalysisSummary summary = analyzer.getTextAnalysisSummary();

    // present information
    cout << "Words: " << summary.numWords  << endl;
    cout << "Syllables: " << summary.numSyllables  << endl;
    cout << "Sentences: " << summary.numSentences  << endl;
    cout << "Grade Level: " << summary.gradeLevel  << endl;

    return 0;
}
