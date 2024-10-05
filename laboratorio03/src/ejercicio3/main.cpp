#include "Lista.h"

int main()
{
  Lista lista;

  lista.insertarInicio(10);
  lista.insertarFinal(20);
  lista.insertarInicio(5);
  lista.insertarInicio(17);
  lista.insertarFinal(30);
  lista.insertarFinal(25);

  cout << "\n[+] Lista desde el inicio: ";
  lista.imprimeDesdeAdelante();

  cout << "\n[+] Lista desde el final: ";
  lista.imprimeDesdeAtras();

  lista.eliminarInicio();
  cout << "[+] Lista despues de eliminar el inicio: ";
  lista.imprimeDesdeAdelante();

  lista.eliminarFinal();
  cout << "[+] Lista despues de eliminar el final: ";
  lista.imprimeDesdeAdelante();

  int valorBuscado = 20;
  Nodo *encontrado = lista.buscarDesdeAdelante(valorBuscado);
  if (encontrado)
    cout << "\nElemento " << valorBuscado << " encontrado desde adelante." << endl;
  else
    cout << "\nElemento " << valorBuscado << " no encontrado desde adelante." << endl;

  encontrado = lista.buscarDesdeAtras(valorBuscado);
  if (encontrado)
    cout << "\nElemento " << valorBuscado << " encontrado desde atras." << endl;
  else
    cout << "\nElemento " << valorBuscado << " no encontrado desde atras." << endl;

  cout << "\n\n[-] Destruyendo la lista..." << endl;

  return 0;
}
