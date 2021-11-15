#include <iostream>

using namespace std;


struct stackElement{
    char delimiter;
    int location;
    stackElement *next;
};

stackElement *head = nullptr;


stackElement pop(){
    if (head != nullptr){
        stackElement *old = head;
        head = head->next;
        return *old;
    }
    else{
        cout << "Tried to pop when stack was empty\n";
    }
}

void push(char delim, int loc){
   stackElement *newElement  = new stackElement;
   newElement->delimiter = delim;
   newElement->location = loc;
   newElement->next = head;
   head = newElement;
}

int main(){
    while(cin){

        bool errorThrown;
        string input;
        getline(cin, input);
        string delimOpenArray = "([{<`";
        string delimCloseArray = ")]}>'";
        for(int i=0 ; i<int(input.length()); i++){
            if(input[i] == delimOpenArray[0] || 
                    input[i] == delimOpenArray[1] ||
                    input[i] == delimOpenArray[2] ||
                    input[i] == delimOpenArray[3] ||
                    input[i] == delimOpenArray[4]){
              push(input[i], i);
            }
            else if(input[i] == delimCloseArray[0] || 
                    input[i] == delimCloseArray[1] ||
                    input[i] == delimCloseArray[2] ||
                    input[i] == delimCloseArray[3] ||
                    input[i] == delimCloseArray[4]){
                stackElement whatIPopped= pop();
                if(whatIPopped.delimiter == '(' && input[i] == ')'){
                }
                else if(whatIPopped.delimiter == '[' && input[i] == ']'){
                }
                else if(whatIPopped.delimiter == '{' && input[i] == '}'){
                }
                else if(whatIPopped.delimiter == '<'&& input[i] == '>'){
                }
                else if(whatIPopped.delimiter == '`' && input[i] == '\''){
                }
                else if(whatIPopped.delimiter == delimOpenArray[0] ||whatIPopped.delimiter ==  delimOpenArray[1] ||whatIPopped.delimiter == delimOpenArray[2] ||whatIPopped.delimiter ==  delimOpenArray[3] ||whatIPopped.delimiter ==  delimOpenArray[4]){
                    errorThrown = true;
                    cout << "INVALID\n";
                    cout << input + "\n";
                    for(int a=0; a<whatIPopped.location; a++){
                        cout << " ";
                    } 
                    cout << "^";
                    for(int b=0; b<(i - whatIPopped.location) - 1; b++){
                        cout << " ";
                    }
                    cout << "^";
                    break;
                }
                else if(errorThrown != true){
                    errorThrown = true;
                    cout << "INVALID\n";
                    cout << input + "\n";
                    for(int c=0;c<i;c++){
                        cout << " ";
                    }
                    cout << "^\n";


                    break;
                
                }
              }
            }
        if(head != nullptr && errorThrown != true){
            cout << "INVALID\n";
            cout << input + "\n";
            for(int a=0; a<head->location; a++){
            cout << " ";
            }
            cout << "^\n";
            errorThrown = true;
         
       }
                if(errorThrown != true && input.length() > 0){
                    cout << "SUCCESS";
               }
    }
}

