#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int N = 1e5 + 5;
int tree[4 * N];
int arr[N];

void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return 0;
    if (l <= start && end <= r) return tree[node];
    int mid = (start + end) / 2;
    int p1 = query(2 * node, start, mid, l, r);
    int p2 = query(2 * node + 1, mid + 1, end, l, r);
    return p1 + p2;
}

void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        arr[idx] = val;
        tree[node] = val;
        return;
    }
    int mid = (start + end) / 2;
    if (idx <= mid) update(2 * node, start, mid, idx, val);
    else update(2 * node + 1, mid + 1, end, idx, val);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void solve() {
    int n;
    cin >> n;
    
    // Generar valores aleatorios para el arreglo
    // random_device rd;
    // mt19937 gen(rd());
    // uniform_int_distribution<> dis(1, 300);
    
    // for (int i = 1; i <= n; i++) {
    //     arr[i] = dis(gen);
    //     cout << arr[i] << " ";
    // }
    // cout << "\n";

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    
    build(1, 1, n);
    
    int q;
    cin >> q;
    
    while (q--) {
        char type;
        cin >> type;
        if (type == 'c') {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << "\n";
        } else {
            int x, v;
            cin >> x >> v;
            update(1, 1, n, x, v);
        }
    }
}

int32_t main() {
    fast;
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}