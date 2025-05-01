// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <cstdint>

using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

void solve() {
    int n;
    cin >> n;

    vector<int> matriz_A(n);
    for (int i = 0; i < n; i++) {
        cin >> matriz_A[i];
    }

    vector<int> matriz_B(n);
    for (int i = 0; i < n; i++) {
        int contador = 0;

        for (int j = 0; j < i; j++) { // para solo se evaluen los dias anteriores a la posicion actual
            if (matriz_A[j] <= matriz_A[i]) {
                contador++;
            }
        }
        matriz_B[i] = contador;
    }

    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += matriz_B[i];
    }

    cout << suma << endl;
}

int32_t main() {
    fast;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}