#include "LogicUnit.h"
#include "Register.h"
#include "Clock.h"

 class RegisterFile : public Listener<5>, public Listener<32>,
 public Listener<1>, public MultiReporter<32, 2>
 {
 // private data members
 Register<32> *regArray[32]; //registers will do their own "thing" with clock
 Value<5> outputRegister0;
 Value<5> outputRegister1;
 Value<5> inputRegister;
 word inputValue;
 Value<1> WEbit;

 public:
 RegisterFile(Clock* synch);

 virtual void update_input(int input_port, Value<5> value) override;
 virtual void update_input(int input_port, word value) override;
 virtual void update_input(int input_port, Value<1> value) override;
 virtual word get_output(int output_port, word ignore) const override;

 //refer to first parameter of update input methods
 const static int Output0RegisterPort = 0;
 const static int Output1RegisterPort = 1;
 const static int InputRegisterPort = 2;
 const static int InputValuePort = 3;
 const static int WEPort = 4;
 };







