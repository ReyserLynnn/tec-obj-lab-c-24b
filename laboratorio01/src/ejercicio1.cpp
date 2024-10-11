#include <iostream>
#include <string>
#include <cstdlib>
#include <filesystem>

#define cube(x) ((x) * (x) * (x))

bool isPerfectCube(int num)
{
  int sumaCubos = 0;
  int original = num;

  while (num > 0)
  {
    int digito = num % 10;
    sumaCubos += cube(digito);
    num /= 10;
  }

  return sumaCubos == original;
}

int main(int argc, char *argv[])
{
  std::string fileName = std::filesystem::path(argv[0]).filename().string();

  if (argc != 2)
  {
    std::cout << "\n[+] Uso: ./" << fileName << " <numero>\n"
              << std::endl;
    return 1;
  }

  int number = std::atoi(argv[1]);

  if (isPerfectCube(number))
  {
    std::cout << "\n[+] " << number << " SI es un cubo perfecto." << std::endl;
  }
  else
  {
    std::cout << "\n[-] " << number << " NO es un cubo perfecto." << std::endl;
  }
  delete[] argv;
  printf("\n\n");
  return 0;
}
