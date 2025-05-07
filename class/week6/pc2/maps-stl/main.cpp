#include <cmath>
#include <cstdint>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


int32_t main() {
    fast;
    
    int q;
    cin >> q;
    
    map<string, int> calificaciones;
    
    while (q--) {
        int tipo;
        string nombre;
        
        cin >> tipo;
        
        if (tipo == 1) {
            int puntos;
            cin >> nombre >> puntos;
            calificaciones[nombre] += puntos;
        } 
        else if (tipo == 2) {
            // Borrar calificaciones
            cin >> nombre;
            calificaciones[nombre] = 0;
        } 
        else if (tipo == 3) {
            // Mostrar calificaciones
            cin >> nombre;
            cout << calificaciones[nombre] << endl;
        }
    }
    
    return 0;
}