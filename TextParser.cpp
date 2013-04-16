/*
 * File: TextParser.cpp
 * ----------------------
 * Name: Eric Beach
 * Section: SCPD, Aaron Broder <abroder@stanford.edu>
 * Copyright 2013 Eric Beach <ebeach@google.com>
 * Assignment 1 - Pt. 4 - Flesch-Kincaid
 * This file implements a class that takes in a file and
 *   parses it with a tokenizer and analyzes the complexity of the writing.
 *
 * This file lightly linted using
 * http://google-styleguide.googlecode.com/svn/trunk/cpplint/cpplint.py
 */

#include <string>
#include <iostream>
#include "TextParser.h"

using namespace std;

/*
 * Constructor to accept a file stream for parsing with a tokenizer.
 */
TextParser::TextParser(istream& fileInput) {
    tokenizer = TokenScanner(fileInput);
}

/*
 * Process input into tokens, for analysis later by another class.
 */
void TextParser::processInput() {
    tokenizer.ignoreWhitespace();

    string currentStr;
    TokenType type;
    Token currentToken;
    while (tokenizer.hasMoreTokens()) {
        currentStr = tokenizer.nextToken();
        type = tokenizer.getTokenType(currentStr);
        currentToken.tokenVal = currentStr;
        currentToken.tokenType = type;
        tokens.add(currentToken);
    }
}

/*
 * Get the tokens parsed from the file stream.
 */
Vector<Token> TextParser::getTokens() {
    return tokens;
}
