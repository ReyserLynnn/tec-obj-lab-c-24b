#ifndef TIME_H
#define TIME_H
#include <memory>
#include <iostream>

using namespace std;
typedef unsigned short int USHORT;

class Time
{
private:
  unique_ptr<USHORT> hour;
  unique_ptr<USHORT> minute;
  unique_ptr<USHORT> second;

public:
  Time(const USHORT h = 0, const USHORT m = 0, const USHORT s = 0);
  Time(const Time &t);
  ~Time() {}

  void setTime(const USHORT h, const USHORT m, const USHORT s);
  void printTime() const;
  bool equals(const Time &T) const;
};

#endif