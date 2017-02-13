//Alena Mitrakhovich
//115 297 152
//Workshop 5
//02/12/2017

#pragma once
#include "Message.h"
#include <iostream>

namespace w5{
  static const int MAX_SIZE = 10;
class Notifications {
  Message* messageTable;
  size_t messageCount;
public:
  Notifications(); //default constructor - empty
  Notifications(const Notifications&); //copy constructor
  Notifications& operator=(const Notifications&); //copy assignment operator
  Notifications(Notifications&&); //move constructor
  Notifications&& operator=(Notifications&&); //move assignment operator
  ~Notifications(); //destructor
  void operator+=(const Message& msg); //adds msg to the set
  void display(std::ostream& os) const; //inserts the Message objects to the os output stream
}; //class Notifications
} //namespace w5