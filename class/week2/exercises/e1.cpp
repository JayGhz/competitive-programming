#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

void decimal_a_binario(int n) {
    if (n == 0) {
        cout << 0;
        return;
    }
    
    // Find the position of the leftmost 1 bit
    int msb = 63 - __builtin_clzll(n);
    
    // Print each bit from left to right using bit shifts
    for (int i = msb; i >= 0; i--) {
        cout << ((n >> i) & 1);
    }
}

void solve() {
    int n;
    cin >> n;
    decimal_a_binario(n);
    cout << endl;
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