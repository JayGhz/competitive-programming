#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

// void imprimir_numeros(int n, int actual) {
//     if (n == 0) return;

//     for (int i = 1; i <= actual; i++) {
//         cout << i;
//     }
//     cout << "\n";
//     imprimir_numeros(n - 1, actual + 1);
// }

// void solve() {
//     int n;
//     cin >> n;
//     imprimir_numeros(n, 1);
// }

void print(int n) {
    if ( n > 0) {
        print(n-1);
        cout << n;
    }
}
 
void triag(int n) {
    if (n > 0) {
        triag(n-1);
        print(n);
        cout << "\n";
    }
}

void solve() {
    int n;
    cin >> n;
    triag(n);
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