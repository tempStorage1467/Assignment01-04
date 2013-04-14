/*
 * File: TextParser.h
 * ----------------------
 * Name: Eric Beach
 * Section: SCPD, Aaron Broder <abroder@stanford.edu>
 * Copyright 2013 Eric Beach <ebeach@google.com>
 * This file defines a class that takes in a file or string and
 *   parses it with a tokenizer and analyzes the complexity of the writing.
 *
 * This file lightly linted using
 * http://google-styleguide.googlecode.com/svn/trunk/cpplint/cpplint.py
 */

#ifndef TEXTPARSER_H_
#define TEXTPARSER_H_

#include <string>
#include <iostream>
#include "vector.h"
#include "tokenscanner.h"

using namespace std;

/*
 * Structure to encapsulate data about a token.
 */
struct Token {
    string tokenVal;
    TokenType tokenType;
};


/*
 * Class definition that parses text into tokens.
 */
class TextParser {
 private:
    // determine whether to show debug information
    bool showDebug = false;

    // tokenizer to read files into tokens
    TokenScanner tokenizer;

    // stack of tokens
    Vector<Token> tokens;

 public:
    // constructor to read in a stream for parsing to tokens
    TextParser(istream& fileStream);

    // process the input streak to tokens
    void processInput();

    // get the processed tokens
    Vector<Token> getTokens();
};

#endif  // TEXTPARSER_H_
