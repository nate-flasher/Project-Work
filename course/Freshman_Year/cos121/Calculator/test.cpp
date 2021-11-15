/**
 * @brief   Calculator class test program.
 * @author  Your name here
 */

#include <iostream>

// #include the Calculator header file right below this.


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


    return 0;
}
