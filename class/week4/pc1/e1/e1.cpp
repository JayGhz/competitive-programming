// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <cstdint>

using namespace std;


#define int long long
#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

bool es_cuadrado(int n) {
    int raiz = sqrt(n);
    return raiz * raiz == n;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> pegs(n);
    vector<int> balls;
    int currentBall = 1;
    
    // Intentamos colocar cada bola
    while (true) {
        bool placed = false;
        
        // Intentamos colocar la bola en cada poste
        for (int i = 0; i < n; i++) {
            bool canPlace = true;
            
            // Verificamos si podemos colocar la bola en este poste
            if (!pegs[i].empty()) {
                int lastBall = pegs[i].back();
                if (!es_cuadrado(lastBall + currentBall)) {
                    canPlace = false;
                }
            }
            
            if (canPlace) {
                pegs[i].push_back(currentBall);
                placed = true;
                break;
            }
        }
        
        if (!placed) break;
        currentBall++;
    }
    
    // Imprimimos el número de bolas colocadas
    cout << currentBall - 1 << "\n";
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