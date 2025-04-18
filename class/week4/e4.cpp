#include <iostream>
using namespace std;

class estudiante {
public:
    int nota;

    estudiante() : nota(0) {}

    estudiante(int n) {
        nota = n; 
    }

    bool estaAprobado() {
        return nota >= 13;
    }

    int getNota() {
        return nota;
    }
};

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

    int getSize() {
        return top + 1;
    }
};

int main() {
    miPila<estudiante> pila(15);
    int aprobados = 0;

    for (int i = 0; i < 15; i++) {
        int nota;
        cout << "Ingrese la nota del estudiante " << i + 1 << ": ";
        cin >> nota;
        estudiante e(nota);
        pila.push(e);
    }

    while (!pila.empty()) {
        estudiante e = pila.getTop();
        if (e.estaAprobado()) {
            aprobados++;
        } 
        pila.pop();
    }

    cout << "Numero de estudiantes desaprobados: " << 15 - aprobados << endl;

    return 0;
}
