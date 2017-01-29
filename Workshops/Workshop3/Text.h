//Alena Mitrakhovich
//115 297 152
//OOP 345 - Workshop 3

#include <string>

#pragma once
using namespace std;

namespace w3 {

  class Text {
    size_t count;
    string* lineTable;
  public:
    Text(); //default constructor 
    Text(const char* file); //1 argument constructor 

    Text(const Text& rhs); //a copy constructor
    Text& operator= (const Text& rhs); //copy assignment operator
    Text(Text&& rhs); //move constructor
    Text& operator= (Text&& rhs); //move assignment operator


    ~Text();//a destructor

    size_t size() const; //returns the number of records of text data

  };

} //namespace w3