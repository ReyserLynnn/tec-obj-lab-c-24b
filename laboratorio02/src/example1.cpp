#include <iostream>

using namespace std;

int main()
{
  unsigned short shortVar = 5;
  unsigned long longVar = 65535;
  long sVar = -65535;

  cout << "shortVar: " << shortVar << endl;
  cout << "Address of shortVar: " << &shortVar << endl;

  cout << "\nlongVar: " << longVar << endl;
  cout << "Address of longVar: " << &longVar << endl;

  cout << "\nsVar: " << sVar << endl;
  cout << "Address of sVar: " << &sVar << endl;

  return 0;
}
