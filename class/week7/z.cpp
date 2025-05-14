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

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    vector<int> z1 = z_function(s1);
    vector<int> z2 = z_function(s2);
    for (int x : z1) {
        cout << x << " ";
    }
    cout << "\n";
    for (int x : z2) {
        cout << x << " ";
    }
    cout << "\n";
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