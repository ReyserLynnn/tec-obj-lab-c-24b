#ifndef NODOOPERACION_H
#define NODOOPERACION_H

#include "Nodo.h"
#include <memory>
#include <iostream>

class NodoOperacion : public Nodo
{
private:
  char operador;
  std::unique_ptr<Nodo> hijoIzquierdo;
  std::unique_ptr<Nodo> hijoDerecho;

public:
  NodoOperacion(char op, std::unique_ptr<Nodo> izq, std::unique_ptr<Nodo> der);
  int evaluar() const override;
  void imprimir() const override;
};

#endif
