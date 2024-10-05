#ifndef NODO_H
#define NODO_H

#include <iostream>

using namespace std;

class Nodo
{
public:
  int valor;
  Nodo *siguiente;
  Nodo *anterior;

  Nodo(int val) : valor(val), siguiente(nullptr), anterior(nullptr) {}

  ~Nodo()
  {
    cout << "\nNodo eliminado: " << valor << endl;
  }
};

#endif
