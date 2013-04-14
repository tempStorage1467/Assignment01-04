/*
 * File: TextParserTest.h
 * ----------------------
 * Name: Eric Beach
 * Section: SCPD, Aaron Broder <abroder@stanford.edu>
 * Copyright 2013 Eric Beach <ebeach@google.com>
 * This file defines a prototype for a class to perform unit tests
 *   on TextParser.
 *
 * This file lightly linted using
 * http://google-styleguide.googlecode.com/svn/trunk/cpplint/cpplint.py
 */

#ifndef TOKENANALYZERTEST_H_
#define TOKENANALYZERTEST_H_

#include <iostream>
#include "TextParser.h"
#include "TokenAnalyzer.h"
using namespace std;

/*
 * Definition of a class used to test token analysis.
 */
class TokenAnalyzerTest {
 public:
    // run the tests on the token analyzer.
    void runTests();

 private:
    // determine whether two integers are equal
    bool assertEquals(int expected, int result);

    // determine whether two doubles are equal
    bool assertEquals(double expected, double result);
};

#endif  // TOKENANALYZERTEST_H_
