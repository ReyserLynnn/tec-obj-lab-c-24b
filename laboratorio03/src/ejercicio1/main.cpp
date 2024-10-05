#include "rectangulo.h"
#include <memory>

using namespace std;

int main()
{
  auto R1 = make_unique<Rectangulo>();
  cout << "\n[+] R1 - Draw(): " << endl;
  R1->Draw();

  auto R2 = make_unique<Rectangulo>(5, 3);
  cout << "\n[+] R2 - Draw(): " << endl;
  R2->Draw();

  cout << "\n[+] R1 - Draw(8, 5): " << endl;
  R1->Draw(8, 5);

  auto R3 = make_unique<Rectangulo>(*R1);
  cout << "\n[+] R3 - Draw(): " << endl;
  R3->Draw();

  auto R4 = make_unique<Rectangulo>(*R2);
  cout << "\n[+] R4 - Draw(): " << endl;
  R4->Draw();

  return 0;
}