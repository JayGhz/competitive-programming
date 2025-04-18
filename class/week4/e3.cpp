#include <iostream>
using namespace std;

template <typename T>
class miCola {
private:
    T* elements;
    int size;
    int front;
    int rear;

public:
    miCola(int s) {
        size = s;
        elements = new T[size];
        front = -1;
        rear = -1;
    }

    ~miCola() {
        delete[] elements;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    bool enqueue(T value) {
        if (isFull()) {
            return false;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % size;
        elements[rear] = value;
        return true;
    }

    bool dequeue() {
        if (isEmpty()) {
            return false;
        }
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % size;
        }
        return true;
    }

    T getFront() {
        if (isEmpty()) {
            cout << "Cola vacia" << endl;
            return T();
        }
        return elements[front];
    }

    miCola<T> operator*(miCola<T>& other) {
        miCola<T> nuevaCola(this->size);
        miCola<T> tempThis = *this;
        miCola<T> tempOther = other;

        while (!tempThis.isEmpty() && !tempOther.isEmpty()) {
            T elemento1 = tempThis.getFront();
            T elemento2 = tempOther.getFront();
            nuevaCola.enqueue(elemento1 * elemento2);
            tempThis.dequeue();
            tempOther.dequeue();
        }

        return nuevaCola;
    }
};

int main() {
    miCola<int> cola(3);

    cola.enqueue(12);
    cola.enqueue(23);
    cola.enqueue(34);

    miCola<int> cola2(3);
    cola2.enqueue(2);
    cola2.enqueue(3);
    cola2.enqueue(2);

    miCola<int> cola3 = cola * cola2;

    while (!cola3.isEmpty()) {
        cout << cola3.getFront() << " ";
        cola3.dequeue();
    }
    return 0;
    