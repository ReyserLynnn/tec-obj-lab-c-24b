#ifndef RECTANGULO_H
#define RECTANGULO_H
#include <memory>
#include <iostream>

typedef unsigned short int USHORT;
using namespace std;

class Rectangulo
{
private:
  unique_ptr<USHORT> width;
  unique_ptr<USHORT> height;
  unique_ptr<int> temperatura;
  unique_ptr<int> presion;
  unique_ptr<int> humedad;

public:
  Rectangulo();
  Rectangulo(USHORT width, USHORT height);
  Rectangulo(const Rectangulo &R);
  ~Rectangulo() {}

  void Draw();
  void Draw(USHORT width, USHORT height) const;
};

#endif // RECTANGULO_H