/**
 * @brief   Calculator class test program.
 * @author  Nate Flasher
 */

#include <iostream>

// #include the Calculator header file right below this.
#include "Calculator.h"

using namespace std;

int main() {

    Calculator calc;

    // Test the constructor. The calculator accumulator (value) should be 0.
    if(calc.getValue() != 0) {
	cout << "Constructor test: fail" << endl;
    } else {
	cout << "Constructor test: pass" << endl;
    }
    
    // Write tests that demonstrate the rest of your Calculator class code works correctly.
    calc.setValue(3);
    cout<<"Set Value to 3" << calc.getValue() << endl;
    calc.clear();
    calc.add(2);
    calc.add(2);
    cout<<"Add 2+2"<<calc.getValue()<<endl;
    calc.clear();
    calc.subtract(5);
    cout<<"Subtract 5 should be -5"<<calc.getValue()<<endl;
    calc.clear();
    calc.setValue(5);
    calc.multiplyBy(5);
    cout<<"Multiply 5 by 5 "<<calc.getValue()<<endl;
    calc.clear();
    calc.setValue(4);
    calc.divideBy(2);
    cout<<"Dividing 4 by 2 should be equal to 2"<<calc.getValue()<<endl;

    return 0;
}
