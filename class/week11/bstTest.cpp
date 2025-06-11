#include "bst.h"
#include <iostream>
#include <ostream>
#include <string>

using namespace std;

struct Estudiante {
  string nombre;
  float promedio;

  bool operator<=(Estudiante otro) { return this->nombre <= otro.nombre; }
};

ostream &operator<<(ostream &out, Estudiante &e) {
  out << "{" << e.nombre << ", " << e.promedio << "}";
  return out;
}

string randStr(int l) {
  string str = "";
  for (size_t i = 0; i < l; i++) {
    str += rand() % 26 + 65;
  }
  return str;
}

int main(int argc, char *argv[]) {
  Bst<Estudiante> *bst = new Bst<Estudiante>();

  for (size_t i = 0; i < 20; i++) {
    bst->insert(Estudiante{randStr(rand() % 5 + 5), (float)(rand() % 21)});
  }

  bst->inOrder([](Estudiante x) { cout << x << '\n'; });

  cout << endl;

  delete bst;

  return 0;
}
