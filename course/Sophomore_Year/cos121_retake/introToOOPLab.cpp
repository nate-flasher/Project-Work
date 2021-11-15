#include <iostream>
#include <vector>
#include <string>
#include <sodium.h>

using namespace std;

template <typename myType>
class ValidPointer{
    private:
        myType *ptr;
        vector<unsigned char> hash_value;

    public:
        ValidPointer(myType *thisPointer);
        bool isValid();

};

template <typename myType>
ValidPointer<myType>::ValidPointer(myType *thisPointer){
    hash_value = vector<unsigned char>(crypto_generichash_BYTES);

    crypto_generichash( this->hash_value.data(), this->hash_value.size(), (unsigned char*)thisPointer->data(), thisPointer->size(), nullptr, 0);
    
    this->ptr = thisPointer;
    
}
template <typename myType>
bool ValidPointer<myType>::isValid(){
    vector<unsigned char> hash_value2(crypto_generichash_BYTES);
    
    crypto_generichash( hash_value2.data(), hash_value2.size(), (unsigned char*)ptr->data(), ptr->size(), nullptr, 0);
    if(hash_value2 == hash_value){
        return true;
    }
    else{
        return false;
    }

    
    
}

int main() {
    if (sodium_init() < 0) {
        return 1;
    }


    string my_string;
    cin >> my_string;

    ValidPointer<string> my_valid_string(&my_string);
    cout << my_valid_string.isValid() << "\n"; // prints 1

    my_string += "additional text";
    cout << my_valid_string.isValid() << "\n"; // prints 0

    return 0;
}
