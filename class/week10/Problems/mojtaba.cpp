#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

// Función para verificar si un número es divisible por k
bool isDivisible(int num, int k) {
    return num % k == 0;
}

// Función para encontrar el segmento más corto en el rango [L,R] cuyo producto sea divisible por k
int findShortestSegment(vector<int>& a, int L, int R, int k) {
    int n = a.size();#include <cstdlib>
    #include <iostream>
    #include <iomanip>
    #include <vector>
    
    using namespace std;
    
    int getSum(vector<int>& fw, int i) {
        int sum = 0;
        ++i;
        
        while (i > 0) {
            sum += fw[i];
            i -= i & -i;
        }
    
        return sum;
    }
    
    void updateFW(vector<int>& fw, int n, int i, int newVal) {
        ++i;
        while (i <= n) {
            fw[i] += newVal;
            i += i & -i;
        }
    }
    
    void constructFenwick(vector<int>& a, vector<int>& fw) {
        fw.resize(a.size() + 1);
        a[0] = 0;
        fw[0] = 0;
        for (auto i = 0; i < fw.size(); ++i) {
            fw[i] = 0;
        }
        for (auto i = 0; i < a.size(); ++i) {
            updateFW(fw, a.size(), i, a[i]);
        }
    }
    
    void printStuff(vector<int> &a, vector<int> &fw) {
        cout << setw(8) << "index"
            << setw(4) << "f"
            << setw(4) << "cf"
            << setw(4) << "fw" << '\n';
        int sum = 0;
        for (auto i = 0; i < a.size(); ++i) {
            sum += a[i];
            cout << setw(8) << i
                << setw(4) << a[i]
                << setw(4) << sum
                << setw(4) << fw[i] << '\n';
        }
        cout << setw(20) << fw[fw.size() - 1] << '\n';
    }
    
    int main(int argc, char const *argv[]) {
        
        int n = 1000000;
        vector<int> a(n);
        vector<int> fw;
    
        srand(42);
        for (auto i = 1; i < n; ++i) {
            a[i] = rand() % 10;
        }
        constructFenwick(a, fw);
    
        // printStuff(a, fw);
    
        cout << getSum(fw, 1000000) << '\n';
    
        return 0;
    }
    int minLength = INT_MAX;
    
    // Para cada posición de inicio posible en el rango [L,R]
    for (int i = L; i <= R; i++) {
        int product = 1;
        
        // Extender el segmento hasta que el producto sea divisible por k o lleguemos al final del rango
        for (int j = i; j <= R; j++) {
            product = (product * a[j]); // Multiplicar por el siguiente elemento
            
            // Si el producto es divisible por k, actualizar la longitud mínima
            if (isDivisible(product, k)) {
                minLength = min(minLength, j - i + 1);
                break; // Ya encontramos un segmento válido, podemos pasar al siguiente inicio
            }
            
            // Si el producto se hace 0, todos los productos futuros serán 0 (divisibles por cualquier k)
            if (product == 0 && k != 0) {
                minLength = min(minLength, j - i + 1);
                break;
            }
        }
    }
    
    // Si no encontramos ningún segmento válido, devolver -1
    return (minLength == INT_MAX) ? -1 : minLength;
}

void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    
    vector<int> a(n+1); // 1-indexed para facilitar la lectura
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    // Procesar cada consulta
    for (int i = 0; i < q; i++) {
        int L, R;
        cin >> L >> R;
        
        // Encontrar y imprimir la longitud del segmento más corto
        cout << findShortestSegment(a, L, R, k) << " ";
    }
}

int32_t main() {
    fast;
    int t = 1; // Por defecto, solo un caso de prueba
    // cin >> t; // Descomentar si hay múltiples casos de prueba
    while (t--) {
        solve();
    }
    return 0;
}