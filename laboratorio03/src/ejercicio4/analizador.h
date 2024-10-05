#ifndef ANALIZADOR_H
#define ANALIZADOR_H

#include <string>
#include <memory>
#include "NodoNumero.h"
#include "NodoOperacion.h"

class Analizador
{
public:
  std::unique_ptr<Nodo> analizar(const std::string &expresion);

private:
  size_t pos = 0;
  std::unique_ptr<Nodo> parseExpresion(const std::string &expresion);
  std::unique_ptr<Nodo> parseTermino(const std::string &expresion);
  std::unique_ptr<Nodo> parseNumero(const std::string &expresion);
};

#endif
