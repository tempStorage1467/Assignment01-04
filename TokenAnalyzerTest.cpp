//
//  TextParserTest.cpp
//  Flesch-Kincaid
//
//  Created by Eric Beach on 4/12/13.
//
//

#include <iostream>

#include "TokenAnalyzerTest.h"
#include "filelib.h"

using namespace std;

bool TokenAnalyzerTest::assertEquals(double expected, double result) {
    if (expected == result) {
        return true;
    } else {
        cout << "FAIL. Expected: " << expected << "; RECEIVED: " <<
        result << endl;
        return false;
    }
}

bool TokenAnalyzerTest::assertEquals(int expected, int result) {
    if (expected == result) {
        return true;
    } else {
        cout << "FAIL. Expected: " << expected << "; RECEIVED: " <<
        result << endl;
        return false;
    }
}

bool TokenAnalyzerTest::runTests() {
    // TEST FILE #1
    ifstream fileStream1;
    openFile(fileStream1, "Hi.txt");
    
    istream& stream1 = fileStream1;
    
    TextParser parser1 = TextParser(stream1);
    parser1.processInput();
    Vector<Token> tokens1 = parser1.getTokens();
    TokenAnalyzer analyzer1 = TokenAnalyzer(tokens1);
    TextAnalysisSummary summary1 = analyzer1.getTextAnalysisSummary();
    
    assertEquals(1, summary1.numWords);
    assertEquals(1, summary1.numSyllables);
    assertEquals(1, summary1.numSentences);

    // TEST FILE #2
    ifstream fileStream2;
    openFile(fileStream2, "Hi2.txt");

    istream& stream2 = fileStream2;
    
    TextParser parser2 = TextParser(stream2);
    parser2.processInput();
    Vector<Token> tokens2 = parser2.getTokens();
    TokenAnalyzer analyzer2 = TokenAnalyzer(tokens2);
    TextAnalysisSummary summary2 = analyzer2.getTextAnalysisSummary();
    
    assertEquals(7, summary2.numWords);
    assertEquals(8, summary2.numSyllables);
    assertEquals(3, summary2.numSentences);
}