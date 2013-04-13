/*
 * File: TextParserTest.h
 * ----------------------
 * Name: Eric Beach
 * Section: [TODO: enter section leader here]
 * Copyright 2013 <Eric Beach>
 * This file defines a prototype for a class to perform unit tests
 *   on TextParser.
 * [TODO: rewrite the documentation]
 *
 * This file lightly linted using
 * http://google-styleguide.googlecode.com/svn/trunk/cpplint/cpplint.py
 */

#ifndef __Flesch_Kincaid__TextParserTest__
#define __Flesch_Kincaid__TextParserTest__

#include <iostream>
#include "TokenAnalyzer.h"
#include "TextParser.h"
using namespace std;

class TokenAnalyzerTest {
public:
    bool runTests();

private:
    bool assertEquals(int expected, int result);
    bool assertEquals(double expected, double result);
};

#endif /* defined(__Flesch_Kincaid__TextParserTest__) */
