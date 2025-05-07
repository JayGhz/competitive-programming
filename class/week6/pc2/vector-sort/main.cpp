#include <cmath>
#include <cstdint>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

void solve() {
    int n;
    cin >> n;
    
    vector<int> numeros(n);
    
    // Leer los n elementos
    for (int i = 0; i < n; i++) {
        cin >> numeros[i];
    }
    
    // Ordenar el vector
    sort(all(numeros));
    
    // Imprimir los elementos ordenados
    for (int i = 0; i < n; i++) {
        cout << numeros[i];
        if (i < n - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

int32_t main() {
    fast;
    solve();
    return 0;
}