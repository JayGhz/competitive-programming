#include <iostream>
#include <list>
#include <string>

using namespace std;

class HashTable {
private:
    static const int TABLE_SIZE = 8;
    list<int> table[TABLE_SIZE];

public:
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    bool hasCollision(int element, int index) {
        return !table[index].empty();
    }

    void insert(int element) {
        int index = hashFunction(element);
        
        if (hasCollision(element, index)) {
            cout << "Collision detectada en la posicion " << index << endl;
            cout << "..." << endl;
        }
        
        for (auto x : table[index]) {
            if (x == element) {
                cout << "Elemento " << element << " ya existe!" << endl;
                return;
            }
        }
        
        table[index].push_back(element);
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "Index " << i << ": ";
            for (auto x : table[i]) {
                cout << x << " -> ";
            }
            cout << "NULL" << endl;
        }
    }
};
int main() {
    HashTable hash;
    int element;
    char choice;

    do {
        cout << "Ingrese un elmento: ";
        cin >> element;
        hash.insert(element);

        std::cout << "\nHash table despues de la insersion:" << std::endl;
        hash.display();

        std::cout << "\nInsertar otro elemento? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
