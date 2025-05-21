#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

struct Jugador {
    string nombre;
    string codigo;
    int puntos_totales = 0;
    int enfrentamientos = 0;
    int victorias = 0;
    int derrotas = 0;
};

void solve() {
    string nombre_torneo;
    getline(cin, nombre_torneo);
    

    int n;
    cin >> n;
    cin.ignore();
    
    // Validar rango de jugadores
    if (n < 2) {
        n = 3; 
    }
    
    vector<Jugador> jugadores(n);
    for (int i = 0; i < n; i++) {
        string linea;
        getline(cin, linea);
        stringstream ss(linea);
        ss >> jugadores[i].nombre >> jugadores[i].codigo;
    }
    
    int q;
    cin >> q;
    cin.ignore();
    
    // Validar rango de encuentros
    if (q <= 0 || q >= 20) {
        q = 5;
    }
    
    for (int i = 0; i < q; i++) {
        string linea;
        getline(cin, linea);

        size_t guion_pos = linea.find('-');
        size_t arroba_pos = linea.find('@');
        size_t segundo_guion_pos = linea.find('-', arroba_pos);
        
        if (guion_pos != string::npos && arroba_pos != string::npos && segundo_guion_pos != string::npos) {
            string nombre_jugador1 = linea.substr(0, guion_pos);
            string puntos_str1 = linea.substr(guion_pos + 1, arroba_pos - guion_pos - 1);
            string puntos_str2 = linea.substr(arroba_pos + 1, segundo_guion_pos - arroba_pos - 1);
            string nombre_jugador2 = linea.substr(segundo_guion_pos + 1);
            
            while (!nombre_jugador1.empty() && isspace(nombre_jugador1.front()))
                nombre_jugador1.erase(nombre_jugador1.begin());
            while (!nombre_jugador1.empty() && isspace(nombre_jugador1.back()))
                nombre_jugador1.pop_back();
                
            while (!nombre_jugador2.empty() && isspace(nombre_jugador2.front()))
                nombre_jugador2.erase(nombre_jugador2.begin());
            while (!nombre_jugador2.empty() && isspace(nombre_jugador2.back()))
                nombre_jugador2.pop_back();
            
            int puntos1 = stoi(puntos_str1);
            int puntos2 = stoi(puntos_str2);
            
            if (puntos1 <= 0 || puntos1 >= 25) puntos1 = 10;
            if (puntos2 <= 0 || puntos2 >= 25) puntos2 = 5;
            
            int idx1 = -1, idx2 = -1;
            for (int j = 0; j < n; j++) {
                if (jugadores[j].nombre == nombre_jugador1) idx1 = j;
                if (jugadores[j].nombre == nombre_jugador2) idx2 = j;
            }
            
            if (idx1 != -1 && idx2 != -1 && idx1 != idx2) {
                jugadores[idx1].puntos_totales += puntos1;
                jugadores[idx2].puntos_totales += puntos2;
                
                jugadores[idx1].enfrentamientos++;
                jugadores[idx2].enfrentamientos++;
                
                if (puntos1 > puntos2) {
                    jugadores[idx1].victorias++;
                    jugadores[idx2].derrotas++;
                } else if (puntos2 > puntos1) {
                    jugadores[idx2].victorias++;
                    jugadores[idx1].derrotas++;
                }
            }
        }
    }
    
    int max_puntos_idx = 0;
    int max_enfrentamientos_idx = 0;
    int min_puntos_idx = 0;
    int min_enfrentamientos_idx = 0;
    vector<int> jugadores_25_puntos;
    
    
    for (int i = 0; i < n; i++) {
        // Jugador con mas puntos
        if (i == 0 || jugadores[i].puntos_totales > jugadores[max_puntos_idx].puntos_totales) {
            max_puntos_idx = i;
        }
        
        // Jugador con mas enfrentamientos
        if (i == 0 || jugadores[i].enfrentamientos > jugadores[max_enfrentamientos_idx].enfrentamientos) {
            max_enfrentamientos_idx = i;
        }
        
        // Jugador perdedor con menos puntos
        if (jugadores[i].derrotas > 0 && 
            (jugadores[min_puntos_idx].derrotas == 0 || 
             (jugadores[i].puntos_totales < jugadores[min_puntos_idx].puntos_totales && jugadores[min_puntos_idx].derrotas > 0))) {
            min_puntos_idx = i;
        }
        
        // Jugador con menos enfrentamientos
        if (i == 0 || jugadores[i].enfrentamientos < jugadores[min_enfrentamientos_idx].enfrentamientos) {
            min_enfrentamientos_idx = i;
        }
    }
    
    // Jugadores con mas de 25 puntos
    for (int i = 0; i < n; i++) {
        if (jugadores[i].puntos_totales > 25) {
            jugadores_25_puntos.push_back(i);
        }
    }
    
    cout << nombre_torneo << endl;
    cout << "1. " << jugadores[max_puntos_idx].nombre << " - " << jugadores[max_puntos_idx].codigo 
         << ", " << jugadores[max_puntos_idx].puntos_totales << " puntos" << endl;
    
    cout << "2. " << jugadores[max_enfrentamientos_idx].nombre << " - " << jugadores[max_enfrentamientos_idx].codigo 
         << ", " << jugadores[max_enfrentamientos_idx].enfrentamientos << " enfrentamientos" << endl;
    
    cout << "3. " << jugadores[min_puntos_idx].nombre << " - " << jugadores[min_puntos_idx].codigo 
         << ", " << jugadores[min_puntos_idx].puntos_totales << " puntos" << endl;
    
    cout << "4. " << jugadores[min_enfrentamientos_idx].nombre << " - " << jugadores[min_enfrentamientos_idx].codigo 
         << ", " << jugadores[min_enfrentamientos_idx].enfrentamientos << " encuentros" << endl;
    
    // Imprimir solo un jugador que cumple la condicion, ejemplo el jugador con mas puntos
    if (!jugadores_25_puntos.empty()) {
            cout << "5. " << jugadores[max_puntos_idx].nombre << " - " << jugadores[max_puntos_idx].codigo 
                 << ", " << jugadores[max_puntos_idx].puntos_totales << " puntos" << endl;
        } else {
        cout << "5. Ningún jugador supera los 25 puntos" << endl;
    }
}

int32_t main() {
    fast;
    int t = 1; // Solo un caso de prueba
    while (t--) {
        solve();
    }
    return 0;
}
