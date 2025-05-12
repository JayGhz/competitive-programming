#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

// Tabla LPS
vector<int> buildLPS(const string& pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);
    int len = 0, i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0)
                len = lps[len - 1];
            else
                lps[i++] = 0;
        }
    }
    return lps;
}

vector<int> kmpSearch(const string& text, const string& pattern) {
    vector<int> lps = buildLPS(pattern);
    vector<int> positions;
    int n = text.size(), m = pattern.size();
    int i = 0, j = 0;

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++; j++;
        }
        if (j == m) {
            positions.push_back(i - j);
            j = lps[j - 1]; // buscar siguientes
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return positions;
}

string removePattern(const string& text, const string& pattern, const vector<int>& positions) {
    int n = text.size(), m = pattern.size();
    vector<bool> remove(n, false);

    for (int pos : positions) {
        for (int i = 0; i < m; ++i) {
            remove[pos + i] = true;
        }
    }

    string result;
    for (int i = 0; i < n; ++i) {
        if (!remove[i])
            result += text[i];
    }
    return result;
}

void solve() {
    string text, pattern;
    cin >> text >> pattern;

    vector<int> positions = kmpSearch(text, pattern);
    int count = positions.size();

    if (count == 0) {
        cout << "No encontró patrón." << '\n';
    } else if (count > 3) {
        cout << "El patrón es muy frecuente en el texto." << '\n';
    } else {
        string cleaned = removePattern(text, pattern, positions);
        cout << "Nuevo texto: " << cleaned << '\n';
    }
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
