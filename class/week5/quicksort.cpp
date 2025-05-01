#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

template <typename T> int getPivot(vector<T>& v, int start, int end) {
  int pivot = start;
  int left = start + 1;
  int right = end;
  while (left <= right) {
    if (v[left] > v[pivot] && v[right] < v[pivot]) {
      swap(v[left], v[right]);
    }
    if (v[left] <= v[pivot]) {
      left++;
    }
    if (v[right] >= v[pivot]) {
      right--;
    }
  }
  if (pivot != right) {
    swap(v[pivot], v[right]);
  }
  return right;
}

template <typename T> void quick(vector<T>& v, int start, int end) {
  if (start >= end) {
    return;
  }

  int pivot = getPivot(v, start, end);
  quick(v, start, pivot - 1);
  quick(v, pivot + 1, end);
}

template <typename T> void quicksort(vector<T>& v) { quick(v, 0, v.size() - 1); }

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

int main(int argc, char **argv) {
  if (argc != 2) {
    return EXIT_FAILURE;
  }

  int n = atoi(argv[1]);
  vector<int> v(n);

  // Utilizamos un generador de numeros aleatorios
  random_device rd;
  mt19937 rng{rd()}; // Motor de numeros aleatorios
  uniform_int_distribution<int> uid(1, 100); // Distribucion de numeros

  for (int i = 0; i < n; i++) {
    v[i] = uid(rng);
  }
//   cout << v << endl;
  quicksort(v);
//   cout << v << endl;

  return EXIT_SUCCESS;
}