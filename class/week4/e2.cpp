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
            throw runtime_error("Queue is empty");
        }
        return elements[front];
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }
};

int main() {
    miCola<int> cola(5);

    cola.enqueue(12);
    cola.enqueue(23);
    cola.enqueue(34);

    cout << "Elemento en la frente: " << cola.getFront() << endl;

    while (!cola.isEmpty()) {
            cout << cola.getFront() << " ";
            cola.dequeue();
     }

    return 0;
}