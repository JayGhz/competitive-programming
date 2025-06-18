#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int N = 1e5 + 5;
int bit[N];
int arr[N];    
int n;      

void add(int idx, int val) {
    while (idx <= n) {
        bit[idx] += val;
        idx += idx & (-idx);
    }
}

void update(int idx, int val) {
    int diff = val - arr[idx];
    arr[idx] = val;
    while (idx <= n) {
        bit[idx] += diff;
        idx += idx & (-idx);
    }
}

int query(int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += bit[idx];
        idx -= idx & (-idx);
    }
    return sum;
}

int rangeQuery(int l, int r) {
    return query(r) - query(l - 1);
}


void build() {
    memset(bit, 0, sizeof(bit));
    for (int i = 1; i <= n; i++) {
        add(i, arr[i]);
    }
}

void solve() {
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    build();
    
    int q;
    cin >> q;

    while (q--) {
        char type;
        cin >> type;
        if (type == 'q') {
            int l, r;
            cin >> l >> r;
            cout << rangeQuery(l, r) << "\n";
        } else if (type == 'u') {
            int x, v;
            cin >> x >> v;
            update(x, v);
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
