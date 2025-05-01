#include <iostream>
#include <vector>

#define MAXN 50

using namespace std;

int exchangeSort(vector<int> &v, int n) {
  int exchanges = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (v[i] > v[j]) {
        swap(v[i], v[j]);
        exchanges++;
      }
    }
  }
  return exchanges;
}

int main(int argc, char *argv[]) {
  int N, L;
  vector<int> v(MAXN);

  cin >> N;

  while (N--) {
    cin >> L;
    for (int i = 0; i < L; i++) {
      cin >> v[i];
    }
    cout << "Optimal train swapping takes " << exchangeSort(v, L) << " swaps.\n";
  }
}