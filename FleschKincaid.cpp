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
#include "TextParserTest.h"

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
    TextParserTest test = TextParserTest();
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
    //   showDebugInformation()
    //
    //   accept istream and read the stream into a vector of tokens
    //
    //   a wrapper layer ontop of the TokenScanner to store the vector
    //     and control what types of tokens count vs. are discarded
    //     wrapper will also count up words, sentences, etc. so we don't have
    //     iterate a file twice (once to tokenize, another time to analyze)
    //
    //   Wrapper will also count as it goes count: numWords, numSentences,
    //                                             numSyllables
    //
    //   Tokenize strings like isn't as a single token isn't rather
    //     than the three tokens isn, ', and t.
    //   Store data in a struct about numWords, numSentences, numSyllables
    TextParser parser = TextParser(stream);
    parser.showDebugInformation(SHOW_DEBUG_INFO);
    parser.processInput();

    // analyze text based upon tokenizer
    //   showDebugInformation
    //   take in a struct with numWords, numSentences, numSyllables
    //   store constants; return getGradeLevel()
    
    // present information
    
    // [TODO: fill in the code]
    return 0;
}
