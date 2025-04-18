#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define fast                                                                   \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);                                                                  \
  cout.tie(0);

void solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  map<int, int> freq;
  for(int x : arr) {
    freq[x]++;
  }

  int maxFreq = 0;
  int ans = 0;
  for(auto [num, count] : freq) {
    if(count > maxFreq) {
      maxFreq = count;
      ans = num;
    } else if(count == maxFreq && num < ans) {
      ans = num;
    }
  }

  cout << ans << "\n";

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