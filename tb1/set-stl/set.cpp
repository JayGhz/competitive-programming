#include <iostream>
#include <vector>
#include <set>
#include <limits>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr;
    for (int i = 0; i < n; ++i) {
        int valor;
        cin >> valor;
        arr.push_back(valor);
    }

    if (cin.peek() != '\n') {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int q;
    cin >> q;

    while (q--) {
        int L, R;
        cin >> L >> R;

        if (L < 0 || R >= n || L > R) {
            cout << "Rango invalido" << endl;
            continue;
        }

        set<int> distintos;
        for (int i = L; i <= R; ++i) {
            distintos.insert(arr[i]);
        }

        cout << "Elementos unicos entre indices " << L << " y " << R << ": " << distintos.size() << endl;

        int objetivo;
        cin >> objetivo;

        if (distintos.count(objetivo)) {
            cout << "El numero " << objetivo << " SI esta presente." << endl;
        } else {
            cout << "El numero " << objetivo << " NO esta presente." << endl;
        }
    }

    return 0;
}