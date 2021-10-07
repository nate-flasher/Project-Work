#include "LogicUnit.h"

const static int num_codes = 4;
 class ALU : public LogicUnit<32>, public Listener<3>,
 public MultiReporter<1, num_codes>
 {
 // member variables here
 word a;
 word b;
 word result;
 Value<3> operation;
 public:
 ALU();



 virtual void update_input(int num, word value) override;
 virtual void update_input(int num, Value<3> value) override;
 virtual word get_output() const override;
 virtual Value<1> get_output(int output, Value<1> ignore) const override;

 const static int Zero = 0;
 const static int Negative = 1;
 const static int Overflow = 2;
 const static int CarryOut = 3;
 };