#include <iostream>

using namespace std;

struct Nodo
{
  int valor;
  Nodo *siguiente;
  Nodo *anterior;

  Nodo(int val) : valor(val), siguiente(nullptr), anterior(nullptr) {}
};

class ListaDobleEnlazada
{
private:
  Nodo *cabeza;
  Nodo *cola;

public:
  ListaDobleEnlazada() : cabeza(nullptr), cola(nullptr) {}

  void insertarFinal(int valor)
  {
    Nodo *nuevoNodo = new Nodo(valor);
    if (cabeza == nullptr)
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

  void insertarInicio(int valor)
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

  void eliminarFinal()
  {
    if (cola == nullptr)
    {
      cout << "La lista está vacía, no se puede eliminar." << endl;
      return;
    }

    if (cabeza == cola)
    {
      delete cabeza;
      cabeza = cola = nullptr;
    }
    else
    {
      Nodo *nodoAEliminar = cola;
      cola = cola->anterior;
      cola->siguiente = nullptr;
      delete nodoAEliminar;
    }
  }

  void eliminarInicio()
  {
    if (cabeza == nullptr)
    {
      cout << "La lista está vacía, no se puede eliminar." << endl;
      return;
    }

    if (cabeza == cola)
    {
      delete cabeza;
      cabeza = cola = nullptr;
    }
    else
    {
      Nodo *nodoAEliminar = cabeza;
      cabeza = cabeza->siguiente;
      cabeza->anterior = nullptr;
      delete nodoAEliminar;
    }
  }

  void mostrarDesdeInicio() const
  {
    Nodo *actual = cabeza;
    while (actual != nullptr)
    {
      cout << actual->valor << " ";
      actual = actual->siguiente;
    }
    cout << endl;
  }

  void mostrarDesdeFinal() const
  {
    Nodo *actual = cola;
    while (actual != nullptr)
    {
      cout << actual->valor << " ";
      actual = actual->anterior;
    }
    cout << endl;
  }

  ~ListaDobleEnlazada()
  {
    while (cabeza != nullptr)
    {
      Nodo *temp = cabeza;
      cabeza = cabeza->siguiente;
      delete temp;
    }
  }
};

int main()
{
  ListaDobleEnlazada lista;

  lista.insertarFinal(10);
  lista.insertarFinal(20);
  lista.insertarInicio(5);
  lista.insertarInicio(1);

  cout << "\n[+] Lista desde el inicio: ";
  lista.mostrarDesdeInicio();

  cout << "[+] Lista desde el final: ";
  lista.mostrarDesdeFinal();

  lista.eliminarInicio();
  cout << "[+] Lista despues de eliminar el inicio: ";
  lista.mostrarDesdeInicio();

  lista.eliminarFinal();
  cout << "[+] Lista despues de eliminar el final: ";
  lista.mostrarDesdeInicio();

  printf("\n");
  return 0;
}
