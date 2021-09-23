#include <iostream>
#include "LogicUnit.h"
#include "common.h"

constexpr int log2(int n) {
    int i = 0;
    while (n > 1) {
        n /= 2;
        ++i;
    }

    return i;
}

template <int size, int width>
class Mux : public LogicUnit<width>, public Listener<log2(size)> {
    // private data members necessary to keep track of inputs
    // private data members necessary to keep track of select bits
    Value<log2(size)> select_bits_value;
    Value<width> returned_value;
    Value<width> input_port_array [size];

public:
    Mux(const std::string& name = "");
    void update_input(int input_port, Value<width> value) override;
    void update_input(int input_port, Value<log2(size)> value) override;
    Value<width> get_output() const override;
};

template<int size, int width>
Mux<size, width>::Mux(const std::string &name) {

}

template <int size, int width>
void Mux<size, width>::update_input(int input_port, Value<width> value) {
    // code to handle input updates here
    this->input_port_array[input_port] = value;

    this->update_listeners();
}

//for our select bits
template <int size, int width>
void Mux<size, width>::update_input(int input_port, Value<log2(size)> value) {
    // code to handle select updates here
    this->select_bits_value = value;

    this->update_listeners();
}

template <int size, int width>
Value<width> Mux<size, width>::get_output() const {
    return Value<width> (this->input_port_array[this->select_bits_value]);
}