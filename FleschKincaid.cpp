/*
 * File: FleschKincaid.cpp
 * ----------------------
 * Name: Eric Beach
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Flesch-Kincaid problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include "console.h"
#include "simpio.h"
#include "filelib.h"
#include "TextParser.h"
#include "TokenAnalyzer.h"
#include "TokenAnalyzerTest.h"

using namespace std;

bool showDebugInformation () {
    string toDebug = getLine("Show debugging information? (Y or N) ");
    while (toDebug != "Y" && toDebug != "y" &&
           toDebug != "N" && toDebug != "n") {
        cout << "Please enter Y or N." << endl;
        toDebug = getLine("Show debugging information? (Y or N) ");
    }
    return (toDebug == "y" || toDebug == "Y");
}

string getFile(ifstream& stream) {
    return promptUserForFile(stream, "Please enter a file to analyze: ");
}

void runTests() {
    TokenAnalyzerTest test = TokenAnalyzerTest();
    test.runTests();
}

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
    analyzer.getTextAnalysisSummary();
    
    // present information
    
    // [TODO: fill in the code]
    return 0;
}
