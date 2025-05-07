#include <iostream>
#include <vector>
#include <math.h>
#include <cstdint>
#include <algorithm>

using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

void solve() {
    int n;
    int max_presupuesto = 5000000;

 

    sort(all(matriz_A), greater<int>()); // ordenamos el vector en orden descendente

    int suma = 0;
    for (int i = 0; i < matriz_A.size(); i++) {
        suma += 2 * pow(matriz_A[i], i + 1);
        if (suma > max_presupuesto) {
            cout << "Too expensive" << endl;
            return;
        }
    }

    cout << suma << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}