#include <iostream>
using namespace std;

template <typename T>
class miPila {
private:
    T* elements;
    int size;
    int top;

public:
    miPila(int s) {
        size = s;
        elements = new T[size];
        top = -1;
    }

    ~miPila() {
        delete[] elements;
    }

    void push(T element) {
        if (top < size - 1) {
            elements[++top] = element;
        }
    }

    void pop() {
        if (top >= 0) {
            top--;
        }
    }

    T& getTop() {
        if (top >= 0) {
            return elements[top];
        }
        throw runtime_error("Pila vacia");
    }

    bool empty() {
        return top == -1;
    }
};

int main() {
    miPila<int> pila(5);
    pila.push(13);
    pila.push(21;
    pila.push(32);
    pila.push(12);

    while (!pila.empty()) {
        cout << pila.getTop() << endl;
        pila.pop();
    }

    return 0;
}