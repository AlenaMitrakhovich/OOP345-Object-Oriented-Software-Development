//Alena Mitrakhovich
//115 297 152
//Workshop 2
//01/21/2017

#pragma once

#include <string>
#include <iostream>

using namespace std;

namespace w2 {
  enum PassType { PASS_STUDENT, PASS_ADULT, PASS_COUNT };

  class Station {
    string stationName;
    unsigned passes[PASS_COUNT];
  public:
    Station(); // default constructor that initializes the instance variables through an initialization list
    Station(fstream& is); 
    void set(const string&, unsigned, unsigned); // sets the instance variables to the values received in its parameters
    void update(PassType, int); // updates the number of passes - sold if negative, added if positive
    unsigned inStock(PassType) const; // returns the number of passes of the requested type
    const string& getName() const; // returns a reference to a string object holding the name of the station
  }; //class Station

}  //namespace w2