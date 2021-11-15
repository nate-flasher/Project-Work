#include <iostream>

using namespace std;

template <typename T>
class QueueElement {
  public:
    T data;
    QueueElement<T> *next;

    QueueElement(const T& init, QueueElement<T> *ptr);
};

template <typename T>
class Queue {
    QueueElement<T> *first;
    QueueElement<T> *last;

  public:
    Queue();
    void enqueue(const T& value);
    T dequeue();

    bool isEmpty() const;
};

template <typename T>
QueueElement<T>::QueueElement(const T& init, QueueElement<T> *ptr)
    : data(init), next(ptr)
{
}

template <typename T>
Queue<T>::Queue() : first(nullptr), last(nullptr) {
}

template <typename T>
void Queue<T>::enqueue(const T& value) {
    if(isEmpty()){
        first = new QueueElement<T>(value, nullptr);
        last = first;
    }
    else{
        last->next = new QueueElement<T>(value, nullptr);
    }
}

template <typename T>
T Queue<T>::dequeue() {
    if(!isEmpty()){
    T result = first->data;
    QueueElement<T> *temp = first;
    first = first->next;
    delete temp;
    return result;
    }
}

template <typename T>
bool Queue<T>::isEmpty() const {
    return first == nullptr;
}

int main(int argc, char **argv) {
    Queue<int> q;

    for (int i = 0; i < 10; ++i) {
	q.enqueue(i);
    }
    for (int i = 0; i < 10; ++i) {
	cout << q.dequeue() << " ";
    }
    cout << "\n";

    for (int i = 0; i >= 0; ++i) {
	q.enqueue(i);
	int out = q.dequeue();

	if (out != i) {
	    cerr << "Wrong value received!!!\n";
	}

	if (i % 10000000 == 0) {
	    cout << i << "\n";
	}
    }

    return 0;
}
