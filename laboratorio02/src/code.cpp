#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Clase que analiza la operación
class Operacion
{
public:
  static char *analizarOperaciones(const string &operacion, int &countOperadores)
  {
    // Reservamos espacio para los operadores, maximo 5 porque se permite un maximo de 6 numeros
    char *operadores = new char[5];
    countOperadores = 0;

    for (char c : operacion)
    {
      if (c == '+' || c == '-' || c == '*' || c == '/')
      {
        operadores[countOperadores++] = c;
      }
    }
    return operadores;
  }
};

// Clase que administra las operaciones matemáticas
class NucleoCalculadora
{
public:
  static int realizarOperacion(int a, int b, char operador)
  {
    switch (operador)
    {
    case '+':
      return a + b;
    case '-':
      return a - b;
    case '*':
      return a * b;
    case '/':
      return (b != 0) ? a / b : 0; // evitar división por 0
    default:
      return 0;
    }
  }
};

// Clase que procesa la operación
class Procesador
{
private:
  int *numeros;        // Almacenaremos los números en un vector dinámico
  char *operadores;    // Almacenaremos los operadores en un vector dinámico
  int countNumeros;    // Contador de números
  int countOperadores; // Contador de operadores

public:
  Procesador(const string &operacion) : countNumeros(0), countOperadores(0)
  {
    // Reservar espacio para un máximo de 6 números
    numeros = new int[6];
    operadores = Operacion::analizarOperaciones(operacion, countOperadores);
    analizarOperacion(operacion);
  }

  void analizarOperacion(const string &operacion)
  {
    stringstream ss(operacion);
    int numero;
    char op;

    // Extraer números
    while (ss >> numero)
    {
      if (countNumeros < 6)
      {
        numeros[countNumeros++] = numero;
      }
      ss >> op; // Extraer operador si lo hay
    }
  }

  int procesar()
  {
    int resultado = numeros[0]; // Iniciar con el primer número
    for (int i = 0; i < countOperadores; ++i)
    {
      resultado = NucleoCalculadora::realizarOperacion(resultado, numeros[i + 1], operadores[i]);
    }
    return resultado;
  }

  // Liberar memoria
  ~Procesador()
  {
    delete[] numeros;    // Liberar el espacio del vector de números
    delete[] operadores; // Liberar el espacio del vector de operadores
  }
};

int main()
{
  string operacion;
  cout << "Ingrese una operación matemática (por ejemplo: 10+37): ";
  cin >> operacion;

  Procesador procesador(operacion);
  cout << "Resultado: " << procesador.procesar() << endl;

  return 0;
}
