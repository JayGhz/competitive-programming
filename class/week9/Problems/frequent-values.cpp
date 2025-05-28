#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct SegmentTree {
    vector<int> tree;
    int n;

    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n, 0);
    }

    void build(vector<int>& freq, int node, int start, int end) {
        if (start == end) {
            tree[node] = freq[start];
        } else {
            int mid = (start + end) / 2;
            build(freq, 2 * node, start, mid);
            build(freq, 2 * node + 1, mid + 1, end);
            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || l > end) {
            return 0;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int p1 = query(2 * node, start, mid, l, r);
        int p2 = query(2 * node + 1, mid + 1, end, l, r);
        return max(p1, p2);
    }
};

void solve(int n, int q) {
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Comprimir valores y calcular frecuencias
    vector<int> values = arr;
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());
    
    map<int, int> valueToIndex;
    for (int i = 0; i < values.size(); i++) {
        valueToIndex[values[i]] = i;
    }
    
    // Almacenar posiciones de cada valor
    vector<vector<int>> positions(values.size());
    for (int i = 0; i < n; i++) {
        positions[valueToIndex[arr[i]]].push_back(i);
    }
    
    // Procesar consultas usando Segment Tree
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--; // Ajustar a índices base 0
        
        // Construir un Segment Tree para esta consulta específica
        vector<int> freqInRange(n, 0);
        
        // Para cada valor único, calcular su frecuencia en el rango [l,r]
        for (int j = 0; j < values.size(); j++) {
            auto start = lower_bound(positions[j].begin(), positions[j].end(), l);
            auto end = upper_bound(positions[j].begin(), positions[j].end(), r);
            int freq = end - start;
            
            // Marcar todas las posiciones de este valor con su frecuencia
            for (auto it = start; it != end; ++it) {
                freqInRange[*it] = freq;
            }
        }
        
        // Construir el Segment Tree con las frecuencias
        SegmentTree st(n);
        st.build(freqInRange, 1, 0, n - 1);
        
        // Consultar el máximo en el rango [l,r]
        int maxFrequency = st.query(1, 0, n - 1, l, r);
        
        cout << maxFrequency << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    while (cin >> n && n != 0) {
        cin >> q;
        solve(n, q);
    }
    
    return 0;
}