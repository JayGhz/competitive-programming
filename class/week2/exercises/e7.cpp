#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define fast                                                                   \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);                                                                  \
  cout.tie(0);
  
void print(int n) {
  if (n > 0) {
    cout << "* ";
    print(n - 1);
  }
}

void rect(int n, int m) {
  if (m > 0) {
    rect(n, m - 1);
    if (n > 0) {
      cout << "* ";
      print(n - 1);
    }
    cout << "\n";
  }
}

void solve() {
  int n, m;
  cin >> n >> m;
  rect(n, m);
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