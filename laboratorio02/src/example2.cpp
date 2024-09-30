#include <iostream>

using namespace std;

int main()
{
  typedef unsigned short int USHORT;
  USHORT myAge;
  USHORT *pAge = &myAge;

  myAge = 5;

  cout << "myAge: " << myAge << endl;
  cout << "pAge: " << pAge << endl;

  pAge = &myAge;
  cout << "\n*pAge: " << *pAge << endl;
  cout << "pAge: " << pAge << endl;

  cout << "\nAsignar nuevo valor al puntero\n";

  *pAge = 7;

  cout << "*pAge: " << *pAge << endl;
  cout << "myAge: " << myAge << endl;
  cout << "pAge: " << pAge << endl;

  cout << "\nAsignar nuevo valor al puntero\n";
  myAge = 9;

  cout << "myAge: " << myAge << endl;
  cout << "*pAge: " << *pAge << endl;
  cout << "pAge: " << pAge << endl;

  return 0;
}