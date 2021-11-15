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
	Calculator calc;
    calc.setValue(5);
    TS_ASSERT_EQUALS( calc.getValue(), 5);
    }

    /**
     * Check that clear works correctly.
     */
    void testClear() {
	Calculator calc;
    calc.setValue(5);
    calc.clear();
    TS_ASSERT_EQUALS( calc.getValue(), 0);
    }

    /**
     * Check that add works correctly.
     */
    void testAdd() {
        Calculator calc; 
        calc.setValue(5);
        calc.add(4);
        TS_ASSERT_EQUALS( calc.getValue(), 9);
    }

    /**
     * Check that subtract works correctly.
     */
    // Write the entire testing function here.

    void testSubtract() {
        Calculator calc; 
        calc.setValue(5);
        calc.subtract(4);
        TS_ASSERT_EQUALS( calc.getValue(), 1);
    }
    /**
     * Check that multiplyBy works correctly.
     */
    // Write the entire testing function here.

    void testMultiply() {
        Calculator calc; 
        calc.setValue(5);
        calc.multiplyBy(4);
        TS_ASSERT_EQUALS( calc.getValue(), 20);
    }
    /**
     * Check that divideBy works correctly.
     */
    // Write the entire testing function here.

    void testdivideBy() {
        Calculator calc; 
        calc.setValue(20);
        calc.divideBy(4);
        TS_ASSERT_EQUALS( calc.getValue(), 5);
    }
};

#endif /*__INSTRUCTOR__TEST_*/
