#include "Time.h"
#include <iomanip>

using namespace std;

Time::Time(const USHORT h, const USHORT m, const USHORT s) : hour(make_unique<USHORT>(h)), minute(make_unique<USHORT>(m)), second(make_unique<USHORT>(s)) {}

Time::Time(const Time &T) : hour(make_unique<USHORT>(*T.hour)), minute(make_unique<USHORT>(*T.minute)), second(make_unique<USHORT>(*T.second)) {}

void Time::setTime(const USHORT h, const USHORT m, const USHORT s)
{
  *hour = h;
  *minute = m;
  *second = s;
}

void Time::printTime() const
{
  cout << setfill('0') << setw(2) << *hour << ":"
       << setfill('0') << setw(2) << *minute << ":"
       << setfill('0') << setw(2) << *second << endl;
}

bool Time::equals(const Time &T) const
{
  return (*hour == *T.hour) && (*minute == *T.minute) && (*second == *T.second);
}