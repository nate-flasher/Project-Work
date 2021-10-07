#include "ALU.h"
#include "LogicUnit.h"
#include "common.h"

enum class ALUop { LeftShift, And, Or, RightShift, SetLessThan,
     Sub, Sum, Xor };

Value<3> toValue(ALUop op) {
     return {static_cast<unsigned long>(op)};
     }

void ALU::update_input(int num, word value) {
    if (num == 0){
        a = value;
    }
    if(num == 1){
        b = value;
    }

    if(operation == toValue(ALUop::LeftShift)){
        result = a << b;
        Reporter<32>::update_listeners();
        MultiReporter<1, 4>::update_listeners();
    }
    if(operation == toValue(ALUop::And)){
        result = a & b;
        Reporter<32>::update_listeners();
        MultiReporter<1, 4>::update_listeners();
    }
    if(operation == toValue(ALUop::Or)){
        result = a | b;
        Reporter<32>::update_listeners();
        MultiReporter<1, 4>::update_listeners();
    }
    if(operation == toValue(ALUop::RightShift)){
        result = a >> b;
        Reporter<32>::update_listeners();
        MultiReporter<1, 4>::update_listeners();
    }
    if(operation == toValue(ALUop::SetLessThan)){
        result = a < b;
        Reporter<32>::update_listeners();
        MultiReporter<1, 4>::update_listeners();
    }
    if(operation == toValue(ALUop::Sub)){
        result = a - b;
        Reporter<32>::update_listeners();
        MultiReporter<1, 4>::update_listeners();
    }
    if(operation == toValue(ALUop::Sum)){
        result = a + b;
        Reporter<32>::update_listeners();
        MultiReporter<1, 4>::update_listeners();
    }
    if(operation == toValue(ALUop::Xor)){
        result = a ^ b;
        Reporter<32>::update_listeners();
        MultiReporter<1, 4>::update_listeners();
    }

}

void ALU::update_input(int num, Value<3> value) {

}

word ALU::get_output() const {
    return result;
}




Value<1> ALU::get_output(int output, Value<1> ignore) const {
    if (output == ALU::Zero){ //zero condition
        if (result == 0){
            return Value<1> {1};
        } else{
            return Value<0> {0};
        }
    }
    if (output == ALU::Negative){ //negative condition
        if (result < 0){
            return Value<1> {1};
        } else{
            return Value<0> {0};
        }
    }
    if (output == ALU::Overflow){ //overflow condition
        if (operation == toValue(ALUop::Sum){
            if((((a > 0) & (b > 0)) & (result <= 0)) | (((a < 0) & (b < 0)) & (result >= 0))){
                return Value<1> {1};
            } else{
                return Value<0> {0};
            }
        }
        if (operation == toValue(ALUop::Sub)) {
            if(a > 0 & b < 0 & result < 0){
                return Value<1> {1};
            }
            else if (a < 0 & b > 0 & result > 0){
                return Value<1> {1};
            } else{
                return Value<0> {0};
            }
        }
        if (operation == toValue(ALUop::LeftShift)) {
            if ((a >> (32 - b)) & (a != 0)) { //we sure this works tho?
                return Value<1>{1};
            } else {
                return Value<0>{0};
            }
        }
        if (operation == toValue(ALUop::RightShift)){
            if((a << (32+b)) & (a !=0)) { //we sure this works tho?
                return Value<1> {1};
            } else{
                return Value<0> {0};
            }
        }
        if (operation == toValue(ALUop::And | operation == toValue(ALUop::Or | toValue(ALUop::SetLessThan | operation == toValue(ALUop::Xor){
            return Value<0> {0};
        };
    }
    if (output == ALU::CarryOut) { //carry condition
        if(operation == toValue(ALUop::Sum) {
            Value<1> carry = 0;
            for (int i = 0; i < 32; i++) {
                ((a << 32) >> 31);
                ((b << 32) >> 31);
                if (a + b >= 2) {
                    carry = 1;
                } else {
                    carry = 0;
                }
                a >> 1;
                b >> 1;
            }
            if (carry == 1) {
                return Value<1>{1};
            } else {
                return Value<0>{0};
            }
        }

        if(operation == toValue(ALUop::Sub) {
            Value<1> carry = 0;
            for (int i = 0; i < 32; i++) {
                ((a << 32) >> 31);
                ((-b << 32) >> 31);
                if (a + b >= 2) {
                    carry = 1;
                } else {
                    carry = 0;
                }
                a >> 1;
                b >> 1;
            }
            if (carry == 1) {
                return Value<1>{1};
            } else {
                return Value<0>{0};
            }
        }

        if(operation == toValue(ALUop::LeftShift) {
            Value<32> x = (a >> (32 - b));
            if ((x & 1) == 1){
                return Value<1> {1};
            } else{
                return Value<0> {0};
            }

        }
        if(operation == toValue(ALUop::RightShift) {
            Value<32> x = (a << (32 - b));
            if ((x & 1) == 1) {
                return Value<1>{1};
            } else {
                return Value<0>{0};
            }
        }

        if (operation == toValue(ALUop::And | operation == toValue(ALUop::Or | toValue(ALUop::SetLessThan | operation == toValue(ALUop::Xor){
            return Value<0> {0};
        };

    }

}




