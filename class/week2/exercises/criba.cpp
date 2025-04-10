#include <bits/stdc++.h>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

// Criba de Eratostenes
vector<bool> criba(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

void solve() {
    // int n;
    // cin >> n;
    // vector<bool> is_prime = criba(n);
    // for (int i = 2; i <= n; i++) {
    //     if (is_prime[i]) {
    //         cout << i << " ";
    //     }
    // }
    // cout << "\n";

    int n;
    cin >> n;
    int* criba = new int[n];
    int lim = sqrt(n);
    memset(criba, 1, n);
    
    for (int i = 2; i <= lim; ++i) {
        if (criba[i]) {
            for (int j = i * i; j <= n; j += i) {
                criba[j] = 0;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (criba[i]) {
            cout << i << " ";
        }
    }

    delete[]criba;
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