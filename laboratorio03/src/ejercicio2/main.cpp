#include "Time.h"

using namespace std;

int main()
{
  auto T1 = make_unique<Time>(23, 12, 59);
  cout << "\n[+] T1: ";
  T1->printTime();

  auto T2 = make_unique<Time>();
  cout << "\n[+] T2: ";
  T2->printTime();

  T2->setTime(12, 34, 56);
  cout << "\n[+] T2 (setTime): ";
  T2->printTime();

  auto T3 = make_unique<Time>(*T1);
  cout << "\n[+] T3: ";
  T1->printTime();

  cout << "\n[+] T1.equals(T2): " << endl;
  if (T1->equals(*T2))
    cout << "\t[+] T1 and T2 are equal." << endl;
  else
    cout << "\t[-] T1 and T2 are not equal." << endl;

  cout << "\n[+] T3.equals(T1): " << endl;
  if (T3->equals(*T1))
    cout << "\t[+] T3 and T1 are equal." << endl;
  else
    cout << "\t[-] T3 and T1 are not equal." << endl;

  cout << "\n\n";
  return 0;
}