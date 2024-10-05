#ifndef NODONUMERO_H
#define NODONUMERO_H

#include "Nodo.h"
#include <iostream>

class NodoNumero : public Nodo
{
private:
  int valor;

public:
  NodoNumero(int v);
  int evaluar() const override;
  void imprimir() const override;
};

#endif
