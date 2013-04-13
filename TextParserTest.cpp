//
//  TextParserTest.cpp
//  Flesch-Kincaid
//
//  Created by Eric Beach on 4/12/13.
//
//

#include <iostream>
#include "TextParserTest.h"
#include "filelib.h"

using namespace std;

TextParserTest::TextParserTest() {
    
}

bool TextParserTest::assertEquals(double expected, double result) {
    if (expected == result) {
        return true;
    } else {
        cout << "FAIL. Expected: " << expected << "; RECEIVED: " <<
        result << endl;
        return false;
    }
}

bool TextParserTest::assertEquals(int expected, int result) {
    if (expected == result) {
        return true;
    } else {
        cout << "FAIL. Expected: " << expected << "; RECEIVED: " <<
        result << endl;
        return false;
    }
}

bool TextParserTest::runTests() {
    // TEST FILE #1
    ifstream fileStream1;
    openFile(fileStream1, "Hi.txt");
    
    // convert ifstream to istream for use by tokenizer
    istream& stream1 = fileStream1;
    
    TextParser parser1 = TextParser(stream1);
    parser1.processInput();
    TextAnalysisSummary summary1 = parser1.getTextAnalysisSummary();
    assertEquals(1, summary1.numWords);
    assertEquals(1, summary1.numSyllables);
    assertEquals(1, summary1.numSentences);

    // TEST FILE #2
    ifstream fileStream2;
    openFile(fileStream2, "Hi2.txt");

    // convert ifstream to istream for use by tokenizer
    istream& stream2 = fileStream2;

    TextParser parser2 = TextParser(stream2);
    parser2.processInput();
    TextAnalysisSummary summary2 = parser2.getTextAnalysisSummary();
    assertEquals(7, summary2.numWords);
    assertEquals(8, summary2.numSyllables);
    assertEquals(3, summary2.numSentences);

}