#include <iostream>

using namespace std;

template <typename T>
class miVector {
private:
    T* elements;
    int size;

public:
    miVector(int s, T initialValue) {
        size = s;
        elements = new T[size];
        for (int i = 0; i < size; ++i) {
            elements[i] = initialValue;
        }
    }

    class iterator {
    private:
        T* current;
    
    public:
        iterator(T* ptr) : current(ptr) {}
        
        bool operator!=(const iterator& other) {
            return current != other.current;
        }
        
        iterator& operator++() {
            current++;
            return *this;
        }
        
        T& operator*() {
            return *current;
        }
    };

    iterator begin() {
        return iterator(elements);
    }

    iterator end() {
        return iterator(elements + size);
    }

    ~miVector() {
        delete[] elements;
    }
};

int main() {
    miVector<float> v(5, 1.5);
    
    for (auto elem : v) {
        cout << elem << " ";
    }
    
    return 0;
}