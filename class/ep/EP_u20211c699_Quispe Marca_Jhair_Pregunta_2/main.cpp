#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

vector<int> z_function(string s) {
    int n = s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

vector<int> find_pattern(string text, string pattern) {
    string concat = pattern + "$" + text;
    vector<int> z = z_function(concat);
    vector<int> result;
    
    for (int i = 0; i < z.size(); i++) {
        if (z[i] == pattern.length()) {
            result.push_back(i - pattern.length() - 1);
        }
    }
    
    return result;
}

string generate_random_arn(int length) {
    string elementos = "AUGC";
    string arn;
    for (int i = 0; i < length; i++) {
        int random_index = rand() % 4;
        arn += elementos[random_index];
    }
    return arn;
}

void solve() {
    int n;
    cout << "Ingresar número de simulaciones: " << endl;
    cin >> n;
    
    string pattern = "UCUCU";
    vector<int> pattern_counts(n);
    int total_patterns = 0;
    
    for (int i = 0; i < n; i++) {
        int length;
        cout << "\nIngresar cantidad de elementos en la cadena: " << endl;
        cin >> length;
        
        while (length <= 100 || length >= 10000) {
            cout << "La longitud debe estar entre 100 y 10000. Ingrese nuevamente: " << endl;
            cin >> length;
        }
        
        string arn = generate_random_arn(length);
        cout << "\nCadena: " << arn << endl;
        
        vector<int> occurrences = find_pattern(arn, pattern);
        
        pattern_counts[i] = occurrences.size();
        total_patterns += occurrences.size();
        
        cout << "Cantidad de apariciones: " << occurrences.size() << endl;
        
        for (int idx : occurrences) {
            cout << "índice: " << idx << endl;
        }
        
        if (occurrences.size() > 3) {
            cout << "\nSe ha encontrado una alta cantidad de hebra ARN" << endl;
        }
    }
    
    cout << "\nCantidad de veces que aparecieron los patrones en las cadenas ARN: " << total_patterns << endl;
    
    int min_patterns = *min_element(all(pattern_counts));
    int min_simulation = find(all(pattern_counts), min_patterns) - pattern_counts.begin() + 1;
    
    cout << "\nEn la simulación " << min_simulation << " se encontraron menos patrones UCUCU." << endl;
}

int32_t main() {
    fast;
    srand(time(0));
    solve();
    return 0;
}