// 2. Se ha seleccionado N números de personas para realizar una encuesta, en un proceso repetitivo se
// ingresa el grado de instrucción (1-Primaria/2-Secundaria/3-Superior) y la edad (entre 15 y 80 años) de
// cada persona. Obtener la edad y el grado de instrucción usando número aleatorios.
// Construya un programa que muestre lo siguiente:
// a) El promedio de edades
// b) La mayor edad.
// c) Cantidad de Personas con instrucción Primaria
// d) Cantidad de Personas con instrucción Secundaria.
// e) Cantidad de Personas con instrucción Superior.
// Nota: Resolver con struct, bucles, arreglos y funciones.

#include <iostream>
#include <string>
#include <cstdlib>
#include <filesystem>
#include <random>

struct Person
{
  int age;
  int education;
};

enum Education : int
{
  PRIMARY = 1,
  SECONDARY,
  SUPERIOR
};

int randonNumber(int min, int max, std::mt19937 &generator)
{
  std::uniform_int_distribution<int> distribution(min, max);
  return distribution(generator);
}

main(int argc, char *argv[])
{
  std::string fileName = std::filesystem::path(argv[0]).filename().string();

  if (argc != 2)
  {
    std::cout << "\n[+] Uso: ./" << fileName << " <numero>\n"
              << std::endl;
  }

  int number = std::atoi(argv[1]);
  int sumAage = 0;
  int averageAge = 0;

  std::random_device rd;
  std::mt19937 generator(rd());

  Person *persons = new Person[number];

  for (int i = 0; i < number; i++)
  {
    int age = randonNumber(15, 80, generator);
    int education = randonNumber(1, 3, generator);

    persons[i].age = age;
    persons[i].education = education;

    sumAage += age;

    std::cout << age << "+";

    // std::cout << "Persona " << i + 1 << " - Edad: " << persons[i].age
    //           << ", Grado de instruccion: " << persons[i].education << std::endl;
  }

  std::cout << "\nSuma de edades: " << sumAage << std::endl;
  std::cout << "\nNumero de personas: " << number << std::endl;
  averageAge = sumAage / number;

  std::cout << "\n[+] Promedio de edades: " << averageAge << std::endl;

  delete[] persons;
  delete[] argv;
  printf("\n\n");
  return 0;
}