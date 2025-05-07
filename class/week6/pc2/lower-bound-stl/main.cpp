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
    for (int i = 0; i < n; i++) {
        cin >> numeros[i];
    }
    
    int q;
    cin >> q;
    
    while (q--) {
        int y;
        cin >> y;
        
        // Usar lower_bound para encontrar el primer elemento >=
        auto it = lower_bound(all(numeros), y);
        
        int indice = it - numeros.begin() + 1;

        if (it != numeros.end() && *it == y) {
            cout << "Yes " << indice << endl;
        } else {
            cout << "No " << indice << endl;
        }
    }
}

int32_t main() {
    fast;
    solve();
    return 0;
}