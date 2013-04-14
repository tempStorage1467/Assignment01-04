/*
 * File: TextParserTest.cpp
 * ----------------------
 * Name: Eric Beach
 * Section: SCPD, Aaron Broder <abroder@stanford.edu>
 * Copyright 2013 Eric Beach <ebeach@google.com>
 * This file tests the class that analyzes the tokens read in from a file.
 *
 * This file lightly linted using
 * http://google-styleguide.googlecode.com/svn/trunk/cpplint/cpplint.py
 */

#include <iostream>
#include <cfloat>
#include "TokenAnalyzerTest.h"
#include "filelib.h"

using namespace std;

/*
 * Function to determine whether two doubles are equal.
 */
bool TokenAnalyzerTest::assertEquals(double expected, double result) {
    // Credit to "Most effective way for float and double comparison"
    //   on StackOverflow, which I modified based upon
    //   http://www.cplusplus.com/reference/cfloat/
    double diff = expected - result;
    if ((diff < DBL_EPSILON) && (-diff > DBL_EPSILON)) {
        return true;
    } else {
        cout << "FAIL. Expected: " << expected << "; RECEIVED: " <<
        result << endl;
        return false;
    }
}

/*
 * Function to determine whether two integers are equal.
 */
bool TokenAnalyzerTest::assertEquals(int expected, int result) {
    if (expected == result) {
        return true;
    } else {
        cout << "FAIL. Expected: " << expected << "; RECEIVED: " <<
        result << endl;
        return false;
    }
}

/*
 * Function to perform end-to-end testing on multiple files.
 */
void TokenAnalyzerTest::runTests() {
    // TEST FILE #1
    ifstream fileStream1;
    openFile(fileStream1, "Hi.txt");

    istream& stream1 = fileStream1;

    TextParser parser1 = TextParser(stream1);
    parser1.processInput();
    Vector<Token> tokens1 = parser1.getTokens();
    TokenAnalyzer analyzer1 = TokenAnalyzer(tokens1);
    analyzer1.showDebugInformation(false);
    TextAnalysisSummary summary1 = analyzer1.getTextAnalysisSummary();

    assertEquals(1, summary1.numWords);
    assertEquals(1, summary1.numSyllables);
    assertEquals(1, summary1.numSentences);
    assertEquals(-3.4, summary1.gradeLevel);

    // TEST FILE #2
    ifstream fileStream2;
    openFile(fileStream2, "Hi2.txt");

    istream& stream2 = fileStream2;

    TextParser parser2 = TextParser(stream2);
    parser2.processInput();
    Vector<Token> tokens2 = parser2.getTokens();
    TokenAnalyzer analyzer2 = TokenAnalyzer(tokens2);
    analyzer2.showDebugInformation(false);
    TextAnalysisSummary summary2 = analyzer2.getTextAnalysisSummary();

    assertEquals(7, summary2.numWords);
    assertEquals(8, summary2.numSyllables);
    assertEquals(3, summary2.numSentences);
    assertEquals(-1.19429, summary2.gradeLevel);

    // TEST FILE #3
    ifstream fileStream3;
    openFile(fileStream3, "Hi3.txt");

    istream& stream3 = fileStream3;

    TextParser parser3 = TextParser(stream3);
    parser3.processInput();
    Vector<Token> tokens3 = parser3.getTokens();
    TokenAnalyzer analyzer3 = TokenAnalyzer(tokens3);
    analyzer3.showDebugInformation(false);
    TextAnalysisSummary summary3 = analyzer3.getTextAnalysisSummary();

    assertEquals(15, summary3.numWords);
    assertEquals(18, summary3.numSyllables);
    assertEquals(4, summary3.numSentences);
    assertEquals(0.0325, summary3.gradeLevel);

    // TEST FILE #4
    ifstream fileStream4;
    openFile(fileStream4, "Blank.txt");

    istream& stream4 = fileStream4;

    TextParser parser4 = TextParser(stream4);
    parser4.processInput();
    Vector<Token> tokens4 = parser4.getTokens();
    TokenAnalyzer analyzer4 = TokenAnalyzer(tokens4);
    analyzer4.showDebugInformation(false);
    TextAnalysisSummary summary4 = analyzer4.getTextAnalysisSummary();

    assertEquals(1, summary4.numWords);
    assertEquals(0, summary4.numSyllables);
    assertEquals(1, summary4.numSentences);
    assertEquals(-15.2, summary4.gradeLevel);
}
