#include "Analizador.h"
#include <cctype>

std::unique_ptr<Nodo> Analizador::analizar(const std::string &expresion)
{
  pos = 0;
  return parseExpresion(expresion);
}

std::unique_ptr<Nodo> Analizador::parseExpresion(const std::string &expresion)
{
  auto nodoIzq = parseTermino(expresion);

  while (pos < expresion.size() && (expresion[pos] == '+' || expresion[pos] == '-'))
  {
    char operador = expresion[pos++];
    auto nodoDer = parseTermino(expresion);
    nodoIzq = std::make_unique<NodoOperacion>(operador, std::move(nodoIzq), std::move(nodoDer));
  }

  return nodoIzq;
}

std::unique_ptr<Nodo> Analizador::parseTermino(const std::string &expresion)
{
  auto nodo = parseNumero(expresion);

  while (pos < expresion.size() && (expresion[pos] == '*' || expresion[pos] == '/'))
  {
    char operador = expresion[pos++];
    auto nodoDer = parseNumero(expresion);
    nodo = std::make_unique<NodoOperacion>(operador, std::move(nodo), std::move(nodoDer));
  }

  return nodo;
}

std::unique_ptr<Nodo> Analizador::parseNumero(const std::string &expresion)
{
  std::string numeroStr;

  while (pos < expresion.size() && std::isdigit(expresion[pos]))
  {
    numeroStr += expresion[pos++];
  }

  return std::make_unique<NodoNumero>(std::stoi(numeroStr));
}
