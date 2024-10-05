#include "NodoNumero.h"

NodoNumero::NodoNumero(int v) : valor(v) {}

int NodoNumero::evaluar() const
{
  return valor;
}

void NodoNumero::imprimir() const
{
  std::cout << valor;
}
