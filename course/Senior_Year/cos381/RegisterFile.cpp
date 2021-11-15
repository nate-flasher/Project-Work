#include "RegisterFile.h"

void RegisterFile::update_input(int input_port, Value<5> value) {
    if (input_port == 0){
        outputRegister0 = value;
    }
    if (input_port == 1){ //where we are reading from
        outputRegister1 = value;
    }
    if (input_port == 2){ //where we are writing to
        regArray[inputRegister]->update_input(0, Value<1> {0}); //what matters now is the last "thing" i told the register file, disregards old register that was set
        inputRegister = value;
    }


        if (WEbit == Value<1>{1} && (inputRegister != Value<5> {0})) {
            regArray[inputRegister]->update_input(0, Value<1> {1});
            regArray[inputRegister]->update_input(0, inputValue);
                update_listeners();
        }else if(WEbit == Value<1>{0}){
            regArray[inputRegister]->update_input(0, Value<1> {0});
            update_listeners();
        }


}

void RegisterFile::update_input(int input_port, word value) {
    if (input_port == 3){
            inputValue = value; //data attempting to write
    }

    if (WEbit == Value<1>{1} && (inputRegister != Value<5> {0})) {
        regArray[inputRegister]->update_input(0, Value<1> {1});
        regArray[inputRegister]->update_input(0, inputValue);
        update_listeners();
    }else if(WEbit == Value<1>{0}){
        regArray[inputRegister]->update_input(0, Value<1> {0});
        update_listeners();
    }


}

void RegisterFile::update_input(int input_port, Value<1> value) {
//clock signal passed on port -1
//WE bit passed on port 0
    if (input_port == 4){
        WEbit = value;
    }

    if (WEbit == Value<1>{1} && (inputRegister != Value<5> {0})) {
        regArray[inputRegister]->update_input(0, Value<1> {1});
        regArray[inputRegister]->update_input(0, inputValue);
        update_listeners();
    }else if(WEbit == Value<1>{0}){
        regArray[inputRegister]->update_input(0, Value<1> {0});
        update_listeners();
    }
}

word RegisterFile::get_output(int output_port, word ignore) const {
    if (output_port == 0){
        return regArray[outputRegister0]->get_output();
    }
    if (output_port == 1){
        return regArray[outputRegister1]->get_output();
    }
}

RegisterFile::RegisterFile(Clock *synch) {
    for(int i = 0; i < 32; i++) {
        regArray[i] = new Register(synch, Value<32> {0});
    }
    tempReg = new Register(synch, Value<32> {0});
}
