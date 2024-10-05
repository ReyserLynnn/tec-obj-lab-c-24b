#include <iostream>
#include "Analizador.h"

using namespace std;

int main()
{
  string expresion;

  cout << "\n[+] Ingrese la expresion: ";
  cin >> expresion;

  Analizador analizador;
  unique_ptr<Nodo> raiz = analizador.analizar(expresion);

  cout << "\n[+] Resultado: " << raiz->evaluar() << endl;

  cout << "\n[+] Arbol de expresion: ";
  raiz->imprimir();

  cout << "\n"
       << endl;

  return 0;
}
