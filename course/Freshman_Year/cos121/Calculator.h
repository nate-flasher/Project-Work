#ifndef CALCULATOR_H
#define CALCULATOR_H

// This file contains the class prototypes and variables. You should read through this,
// but do not need to write any code in "Calculator.h".

/**
 *  This class represents a simple calculator that contains a single
 *  integer accumulator.  It provides basic methods to set/get/clear the
 *  accumulator's value, as well as to add, subtract, multiply, and
 *  divide.  All operations leave their results in the accumulator for
 *  further manipulation.
 *
 *  @author  Stephen Edwards
 *  @author Stefan Brandle (modifications)
 *  @version 2006.06.14
 */

class Calculator {
  public:
    /**
     * Constructor: initializes a new Calculator object with zero in the accumulator.
     */
        Calculator();

    /**
     * Destructor: does any final cleanup for the object (e.g., returning memory to the memory manager)
     * before object is destroyed.
     */
        virtual ~Calculator();

    /**
     * Retrieve the current value stored in the accumulator.
     * @return the accumulator's value
     */
    virtual int getValue() const;

    /**
     * Sets the value of the accumulator to a new value.
     * @param val the new accumulator value
     */
    virtual void setValue( int val );

    /**
     * Clears the accumulator by setting its value to zero.
     */
    virtual void clear();

    /**
     * Update the accumulator by adding a number to it.
     * @param val the amount to add
     */
    virtual void add( int val );

    /**
     * Update the accumulator by subtracting a number from it.
     * @param val the amount to subtract
     */
    virtual void subtract( int val );

    /**
     * Update the accumulator by multiplying it by a specified amount.
     * @param val the amount to multiply by
     */
    virtual void multiplyBy( int val );

    /**
     * Update the accumulator by dividing it by a specified amount.
     * @param val the amount to divide by
     */
    virtual void divideBy( int val );

  private:
    int value;
};

#endif /*CALCULATOR_H*/
