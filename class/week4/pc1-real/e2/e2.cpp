#include <iostream>
#include <math.h>
#include <cstdint>
#include <queue>

using namespace std;

void solve() {
    int l, m;
    cin >> l >> m;
    l *= 100; // convertimos a centimetros
    
    queue<int> left, right; // cola para almacenar las longitudes de los vehiculos en cada lado
    for(int i = 0; i < m; i++) {
        int len;
        string side;
        cin >> len >> side;
        if(side == "left") left.push(len);
        else right.push(len);
    }
    
    bool isLeft = true; 
    int trips = 0;
    
    while(!left.empty() || !right.empty()) {
        int disponible = l;
        bool cargado = false;
        
        if(isLeft) {
            while(!left.empty() && left.front() <= disponible) {
                disponible -= left.front();
                left.pop();
                cargado = true;
            }
        } else {
            while(!right.empty() && right.front() <= disponible) {
                disponible -= right.front();
                right.pop();
                cargado = true;
            }
        }
        
        // solo avanzamos si se cargo algun vehiculo en el lado actual o si hay vehiculos en el otro lado
        if(cargado || (isLeft && !right.empty()) || (!isLeft && !left.empty())) {
            trips++;
            isLeft = !isLeft;
        }
    }
    
    cout << trips << "\n";
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}