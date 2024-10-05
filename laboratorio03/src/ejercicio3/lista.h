#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"

class Lista
{
private:
  Nodo *cabeza;
  Nodo *cola;

public:
  Lista();
  ~Lista();

  void insertarInicio(int valor);
  void insertarFinal(int valor);

  void eliminarInicio();
  void eliminarFinal();

  void imprimeDesdeAdelante() const;
  void imprimeDesdeAtras() const;

  Nodo *buscarDesdeAdelante(int valor) const;
  Nodo *buscarDesdeAtras(int valor) const;

  void destruyeLista();
};

#endif
