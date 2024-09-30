#include <iostream>
#include <string>

class Operacion
{
public:
  static char *analizarOperaciones(const std::string &operacion, int &countOperadores)
  {
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
      return (b != 0) ? a / b : 0;
    default:
      return 0;
    }
  };
};

class Procesador
{
private:
  int *numeros;
  char *operadores;
  int countNumeros;
  int countOperadores;

public:
  Procesador(const std::string &operacion) : countNumeros(0), countOperadores(0)
  {
    numeros = new int[6];
    operadores = Operacion::analizarOperaciones(operacion, countOperadores);
    analizarOperacion(operacion);
  }

  void analizarOperacion(const std::string &operacion)
  {
    int num = 0;
    bool isNum = false;

    for (int i = 0; i < operacion.size(); i++)
    {
      char c = operacion[i];

      if (isdigit(c))
      {
        num = num * 10 + (c - '0');
        isNum = true;
      }
      else if (c == '+' || c == '-' || c == '*' || c == '/')
      {
        if (isNum)
        {
          if (countNumeros < 6)
          {

            numeros[countNumeros++] = num;
            num = 0;
          }
          isNum = false;
        }
      }
    }

    if (isNum && countNumeros < 6)
    {
      numeros[countNumeros++] = num;
    }
  }

  int procesar()
  {
    int resultado = numeros[0];

    for (int i = 0; i < countOperadores; i++)
    {
      resultado = NucleoCalculadora::realizarOperacion(resultado, numeros[i + 1], operadores[i]);
    }

    return resultado;
  }

  ~Procesador()
  {
    delete[] numeros;
    delete[] operadores;
  }
};

int main()
{

  std::cout << "\n[+] Ingrese la operacion a realizar: ";

  std::string operacion;
  std::cin >> operacion;

  Procesador procesador(operacion);
  std::cout << "\n[+] Resultado: " << procesador.procesar() << std::endl;

  return 0;
}
