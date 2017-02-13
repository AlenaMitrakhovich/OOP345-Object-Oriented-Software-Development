//Alena Mitrakhovich
//115 297 152
//Workshop 5
//02/12/2017

#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
namespace w5 {
  class Message {
    string name, reply, tweet;
  public:
    Message() {}
    Message(std::ifstream& in, char c); //constructor retrieves a record from the in file object, parses the record(as described above) and stores its components in the Message object.c is the character that delimits each record
    bool empty() const; //returns true if the object is in a safe empty state
    void display(std::ostream&) const; //displays the Message objects within the container
  }; //class Message
} //namespace w5