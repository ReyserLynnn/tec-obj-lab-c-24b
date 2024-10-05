#include "Lista.h"

Lista::Lista() : cabeza(nullptr), cola(nullptr)
{
  cout << "\n[+] Constructor por defecto" << endl;
}

Lista::~Lista()
{
  destruyeLista();
  cout << endl;
}

void Lista::insertarInicio(int valor)
{
  Nodo *nuevoNodo = new Nodo(valor);

  if (cabeza == nullptr)
  {
    cabeza = cola = nuevoNodo;
  }
  else
  {
    nuevoNodo->siguiente = cabeza;
    cabeza->anterior = nuevoNodo;
    cabeza = nuevoNodo;
  }
}

void Lista::insertarFinal(int valor)
{
  Nodo *nuevoNodo = new Nodo(valor);

  if (cola == nullptr)
  {
    cabeza = cola = nuevoNodo;
  }
  else
  {
    cola->siguiente = nuevoNodo;
    nuevoNodo->anterior = cola;
    cola = nuevoNodo;
  }
}

void Lista::eliminarInicio()
{
  if (cabeza == nullptr)
  {
    cout << "\n[-] No se puede eliminar, la lista está vacía." << endl;
    return;
  }

  Nodo *nodoAEliminar = cabeza;

  if (cabeza == cola)
  {
    cabeza = cola = nullptr;
  }
  else
  {
    cabeza = cabeza->siguiente;
    cabeza->anterior = nullptr;
  }

  delete nodoAEliminar;
}

void Lista::eliminarFinal()
{
  if (cola == nullptr)
  {
    cout << "\n[-] No se puede eliminar, la lista está vacía." << endl;
    return;
  }

  Nodo *nodoAEliminar = cola;

  if (cabeza == cola)
  {
    cabeza = cola = nullptr;
  }
  else
  {
    cola = cola->anterior;
    cola->siguiente = nullptr;
  }

  delete nodoAEliminar;
}

void Lista::imprimeDesdeAdelante() const
{
  Nodo *actual = cabeza;
  cout;
  while (actual != nullptr)
  {
    cout << actual->valor << " ";
    actual = actual->siguiente;
  }
  cout << endl;
}

void Lista::imprimeDesdeAtras() const
{
  Nodo *actual = cola;
  cout;
  while (actual != nullptr)
  {
    cout << actual->valor << " ";
    actual = actual->anterior;
  }
  cout << endl;
}

Nodo *Lista::buscarDesdeAdelante(int valor) const
{
  Nodo *actual = cabeza;
  while (actual != nullptr)
  {
    if (actual->valor == valor)
      return actual;
    actual = actual->siguiente;
  }
  return nullptr;
}

Nodo *Lista::buscarDesdeAtras(int valor) const
{
  Nodo *actual = cola;
  while (actual != nullptr)
  {
    if (actual->valor == valor)
      return actual;
    actual = actual->anterior;
  }
  return nullptr;
}

void Lista::destruyeLista()
{
  Nodo *actual = cabeza;
  while (actual != nullptr)
  {
    Nodo *siguiente = actual->siguiente;
    delete actual;
    actual = siguiente;
  }
  cabeza = cola = nullptr;
}
