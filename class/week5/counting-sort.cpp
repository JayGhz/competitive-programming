#include <iostream>
#include <random>
#include <vector>

using namespace std;

template <typename T> void countingSort(vector<T> &v) {
  if (v.empty()) return;
  
  T max = v[0];
  for (int i = 1; i < v.size(); i++) {
    if (v[i] > max) {
      max = v[i];
    }
  }

  vector<int> count(max + 1, 0);
  for (int i = 0; i < v.size(); i++) {
    count[v[i]]++;
  }

  for (int i = 1; i <= max; i++) {
    count[i] += count[i-1];
  }

  vector<T> temp(v.size());
  for (int i = v.size() - 1; i >= 0; i--) {
    temp[count[v[i]] - 1] = v[i];
    count[v[i]]--;
  }
  v.swap(temp);
}

ostream &operator<<(ostream &os, vector<int> v) {
  os << "[";
  for (int i = 0; i < v.size(); i++) {
    os << v[i];
    if (i < v.size() - 1) {
      os << ",";
    }
  }
  os << "]";
  return os;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    return EXIT_FAILURE;
  }
  int n = atoi(argv[1]);
  vector<int> v(n);

  // Utilizamos un generador de numeros aleatorios
  random_device rd;
  mt19937 rng{rd()};                         // Motor de numeros aleatorios
  uniform_int_distribution<int> uid(1, 100000); // Distribucion de numeros

  for (int i = 0; i < n; i++) {
    v[i] = uid(rng);
  }
  cout << v << endl;
  countingSort(v);
  cout << v << endl;
  return EXIT_SUCCESS;
}