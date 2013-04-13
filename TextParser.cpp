/*
 * File: TextParser.cpp
 * ----------------------
 * Name: Eric Beach
 * Section: [TODO: enter section leader here]
 * Copyright 2013 <Eric Beach>
 * This file implements a class that takes in a file or string and
 *   parses it with a tokenizer and analyzes the complexity of the writing.
 * [TODO: rewrite the documentation]
 *
 * This file lightly linted using
 * http://google-styleguide.googlecode.com/svn/trunk/cpplint/cpplint.py
 */

#include "TextParser.h"
#include <iostream>
using namespace std;

TextParser::TextParser(string strInput) {
    tokenizer = TokenScanner(strInput);
}

TextParser::TextParser(istream& fileInput) {
    tokenizer = TokenScanner(fileInput);
}

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

Vector<Token> TextParser::getTokens() {
    return tokens;
}