#ifndef __INSTRUCTOR__TEST_
#define __INSTRUCTOR__TEST_

#include <cxxtest/TestSuite.h>
#include "Calculator.h"

/**
 *  Test class for Calculator.
 *
 *  @author  Stephen Edwards
 *  @version 2006.06.14
 *  Modified by Stefan Brandle
 *
 *  Comments: The class declaration line right below must be all on the same line, 
 *    else you get a compiler error. Astounding, but true.
 */

class Instructor__test : public CxxTest::TestSuite {
public:
    /**
     * Check that a new calculator starts off with a zero value.
     */
    void testInitial() {
        Calculator calc;
        TS_ASSERT_EQUALS( calc.getValue(), 0 );
    }

    /**
     * Check that setValue/getValue work correctly.
     */
    void testSetValue1() {
	// Put testing code here.
    }

    /**
     * Check that clear works correctly.
     */
    void testClear() {
	// Put testing code here.
    }

    /**
     * Check that add works correctly.
     */
    void testAdd() {
    }

    /**
     * Check that subtract works correctly.
     */
    // Write the entire testing function here.

    /**
     * Check that multiplyBy works correctly.
     */
    // Write the entire testing function here.

    /**
     * Check that divideBy works correctly.
     */
    // Write the entire testing function here.

};

#endif /*__INSTRUCTOR__TEST_*/
