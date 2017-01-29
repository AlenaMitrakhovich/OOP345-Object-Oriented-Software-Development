//Alena Mitrakhovich
//115 297 152
//Workshop 2
//01/21/2017

#include <string>
#include <fstream>
#include "Station.h"

using namespace std;

namespace w2 {

  Station::Station() {
    stationName = " ";
    passes[PASS_STUDENT] = 0;
    passes[PASS_ADULT] = 0;
  }

  Station::Station(fstream& is) {
    /*string line;
    getline(is, line);
    size_t index = 0;
    string name;
    while (index < line.size()) {
      if (line[index] != ';') {
        name += line[index];
        index++;
      }
      else {
        break;
      }
    }*/
    string name;
    getline(is, name, ';');
    int student = 0;
    int adult = 0;
    is >> student;
    is >> adult;
    set(name, student, adult);
  }

  void Station::set(const string& name, unsigned student, unsigned adult) {
    stationName          = name;
    passes[PASS_STUDENT] = student;
    passes[PASS_ADULT]   = adult;
  }

  unsigned Station::inStock(PassType pt) const {
    return passes[pt];
  }

  const string& Station::getName() const {
    return stationName;
  }

  void Station::update(PassType pt, int change) {
    passes[pt] += change;
  }

} //namespace w2