//Alena Mitrakhovich
//115 297 152
//Workshop 2
//01/21/2017

#pragma once
#include "Station.h"

namespace w2 {
  class Stations {
    int stationCount;
    Station* stationTable;
  public:
    Stations(char* f);
    ~Stations();
    void update();
    void restock();
    void report();
  }; //class Stations

} //namespace w2