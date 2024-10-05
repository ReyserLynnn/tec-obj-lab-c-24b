#include "NodoOperacion.h"
#include <stdexcept>

NodoOperacion::NodoOperacion(char op, std::unique_ptr<Nodo> izq, std::unique_ptr<Nodo> der)
    : operador(op), hijoIzquierdo(std::move(izq)), hijoDerecho(std::move(der)) {}

int NodoOperacion::evaluar() const
{
  int valorIzq = hijoIzquierdo->evaluar();
  int valorDer = hijoDerecho->evaluar();

  switch (operador)
  {
  case '+':
    return valorIzq + valorDer;
  case '-':
    return valorIzq - valorDer;
  case '*':
    return valorIzq * valorDer;
  case '/':
    if (valorDer == 0)
    {
      throw std::runtime_error("Error: Division por cero");
    }
    return valorIzq / valorDer;
  default:
    throw std::runtime_error("Operador desconocido");
  }
}

void NodoOperacion::imprimir() const
{
  std::cout << "(";
  hijoIzquierdo->imprimir();
  std::cout << " " << operador << " ";
  hijoDerecho->imprimir();
  std::cout << ")";
}