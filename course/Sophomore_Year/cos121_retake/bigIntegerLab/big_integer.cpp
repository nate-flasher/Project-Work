#include "big_integer.h"

bool BigInteger::isEven() const{

    int lastChar = value.back();

    if(lastChar == '0' || lastChar == '2' || lastChar == '4' || lastChar == '6' || lastChar == '8'){
        return true;
    }
    else{
        return false;
    }
    
}

BigInteger BigInteger::half() const{

    BigInteger exp = *this;
    string result = "";
    int remainder;
    for(int i= 0; i < exp.value.length(); i++){
        int digit = (int)exp.value[i] -48;

        if(remainder == 1){
            digit = digit + 10;
        }
        int dividedBy2 = digit / 2;
        remainder = digit % 2;
        result = result + to_string(dividedBy2);

    }
    if(result.front() == '0' && result.length() > 1){
        result = result.substr(1);
    }
    return result;
}

BigInteger BigInteger::operator^(const BigInteger& exp) const { 
    BigInteger bigintegerone = BigInteger(1);


    BigInteger baseNumber = *this;
    if(exp == BigInteger(0)){
        return bigintegerone;
    }

    if(exp.isEven()){
        BigInteger evenPartialResult = (baseNumber^(exp.half()));
        cout <<"even partial result: " << evenPartialResult.value << endl; 
        BigInteger evenResult = evenPartialResult * evenPartialResult;
        return evenResult;
    
    }

    else{
        BigInteger oddPartialResult = (baseNumber^(exp.half()));
        cout <<"odd partial result: " << oddPartialResult.value << endl; 
        BigInteger oddResult = baseNumber * oddPartialResult * oddPartialResult;
        cout <<"odd result: " << oddResult.value << endl; 
        return oddResult;
    }


}

BigInteger::BigInteger(const int start) { //done
    value = std::to_string(start);
}

BigInteger::BigInteger(const std::string& start) : value(start) { //done
}

BigInteger BigInteger::operator+(const BigInteger& other) const { //done
    BigInteger biginteger;
    biginteger.value = "";
    int carry = 0;
    if(value.length() > other.value.length()){
        for(int i = 0; i < value.length(); i++){ 
            if(i >= other.value.length()){
                int index = (value.length()-i)-1;
                int a = (int)value[index] -48;
                int sum = ( a + 0 ) + carry;
                int secondDigit = sum % 10;
                biginteger.value = to_string(secondDigit) + biginteger.value; //Biginteger.value takes in ones digit
                carry = sum / 10;
            }
            else{
                int indexA = (value.length()-i)-1;
                int indexB = (other.value.length()-i)-1;
                int a = ((int)value[indexA]) -48;
                int b = ((int)other.value[indexB]) -48; //Converting from ascii value to "real" int value
                int sum = ( a + b ) + carry;
                int secondDigit = sum % 10;
                biginteger.value = to_string(secondDigit) + biginteger.value; //Biginteger.value takes in ones digit
                carry = sum / 10;
            
            }

        }
    }
    else if(other.value.length() > value.length()){
        for(int i = 0; i < other.value.length(); i++){ 
            if(i >= value.length()){
                int index = (other.value.length()-i)-1;
                int b = (int)other.value[index] -48;
                int sum = ( b + 0 ) + carry;
                int secondDigit = sum % 10;
                biginteger.value = to_string(secondDigit) + biginteger.value; //Biginteger.value takes in ones digit
                carry = sum / 10;
            }
            else{
                int indexA = (other.value.length()-i)-1;
                int indexB = (value.length()-i)-1;
                int a = (int)value[indexB] -48;
                int b = (int)other.value[indexA] -48; //Converting from ascii value to "real" int value
                int sum = ( a + b ) + carry;
                int secondDigit = sum % 10;
                biginteger.value = to_string(secondDigit) + biginteger.value; //Biginteger.value takes in ones digit
                carry = sum / 10;

            }

        }
        
    }
    else{
        for(int i = 0; i < value.length(); i++){ 
            int index = (value.length()-i)-1;
            int a = (int)value[index] -48;
            int b = (int)other.value[index] -48; //Converting from ascii value to "real" int value
            int sum = ( a + b ) + carry;
            int secondDigit = sum % 10;
            biginteger.value = to_string(secondDigit) + biginteger.value; //Biginteger.value takes in ones digit
            carry = sum / 10;
        }
        
    }
    if(carry != 0){
        biginteger.value = to_string(carry) + biginteger.value;
    }
        return biginteger;

}

BigInteger BigInteger::operator*(const BigInteger& other) const { //TO DO
    BigInteger totalProduct;
    totalProduct.value = "";
    
    for(int lower = 0; lower < other.value.length(); lower++){

        int carry = 0;
        int indexLower = (other.value.length()-lower)-1;
        int lowerValue = (int)other.value[indexLower] -48;
        
        BigInteger partialProduct = 0;
        

        for(int higher = 0; higher < value.length(); higher++){

            int indexHigher = (value.length()-higher)-1;
            int higherValue = (int)value[indexHigher] -48;

            int product = ( lowerValue * higherValue) + carry;
            int secondDigit = product % 10;
            carry = product / 10;
            partialProduct.value = to_string(secondDigit) + partialProduct.value;
        }
        for(int i = 0; i < lower; i++){
            partialProduct.value = partialProduct.value + "0";   
        }
        if(carry != 0){
            partialProduct.value = to_string(carry) + partialProduct.value;
        }
        cout << "partial = " << partialProduct.value << endl;
       totalProduct = totalProduct + partialProduct; 
    }
    if(totalProduct.value != "0"){
        totalProduct.value = totalProduct.value.substr(0, totalProduct.value.length()-1); 
    }
    cout << "MULT VALUE =" << totalProduct.value << endl;
    return totalProduct;
}

bool BigInteger::operator<(const BigInteger& other) const { //done
    if(value.length() < other.value.length()){
        return true;
    }
    else if(other.value.length() < value.length()){
        return false;
    }
    else{
        for(int i = 0; i<other.value.length(); i++){
            if (value[i] < other.value[i]){
                return true;
            }
            else if( value[i] > other.value[i]){
                return false;
            }
        }
        return false;
    }
}

bool BigInteger::operator==(const BigInteger& other) const { //done
    return value == other.value;
}

void BigInteger::display(std::ostream& out) const { //done
    out << value;
}
