#include <iostream>

using namespace std;

struct IntStackElement {
    int data;
    IntStackElement *next;
};

struct CharStackElement {
    char data;
    CharStackElement *next;
};

template <typename T>
bool isEmpty(T *stack);

template <typename T, typename S>
S pop(T *stack);

template <typename T, typename S>
void push(T *stack, S next_value);

template <typename T, typename S>
void push(T *stack, S next_value) {
    T *temp = new T;

    temp->data = next_value;
    temp->next = stack;
    stack = temp;
}

template <typename T, typename S>
S pop(T *stack) {
    if (!isEmpty(stack)) {
	S result = stack->data;
	T *old = stack;
	stack = stack->next;
	delete old;

	return result;
    }
}

template <typename T>
bool isEmpty(T *stack) {
    return stack == nullptr;
}

int main(int argc, char **argv) {
    IntStackElement *first_stack = nullptr;
    CharStackElement *second_stack = nullptr;

    while (true) {
	push(first_stack, 42);
	int x = pop<IntStackElement, int>(first_stack);
	push(second_stack, '*');
	char y = pop<CharStackElement, char>(second_stack);
    }

    return 0;
}
