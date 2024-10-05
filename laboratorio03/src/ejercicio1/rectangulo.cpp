#include "rectangulo.h"

Rectangulo::Rectangulo()
    : width(make_unique<USHORT>(1)), height(make_unique<USHORT>(1)),
      temperatura(make_unique<int>(0)), presion(make_unique<int>(0)), humedad(make_unique<int>(0)) {}

Rectangulo::Rectangulo(USHORT w, USHORT h) : width(make_unique<USHORT>(w)), height(make_unique<USHORT>(h)),
                                             temperatura(make_unique<int>(0)), presion(make_unique<int>(0)), humedad(make_unique<int>(0)) {}

Rectangulo::Rectangulo(const Rectangulo &R) : width(make_unique<USHORT>(*R.width)), height(make_unique<USHORT>(*R.height)),
                                              temperatura(make_unique<int>(*R.temperatura)), presion(make_unique<int>(*R.presion)), humedad(make_unique<int>(*R.humedad)) {}

void Rectangulo::Draw()
{
  // cout << "\n[*} Dibujando un rectangulo de " << width << "x" << height << endl;
  *temperatura = 25;
  *presion = 1013;
  *humedad = 50;

  Draw(*width, *height);
}

void Rectangulo::Draw(USHORT w, USHORT h) const
{
  for (USHORT i = 0; i < h; i++)
  {
    for (USHORT j = 0; j < w; j++)
    {
      cout << "* ";
    }
    cout << endl;
  }
}
