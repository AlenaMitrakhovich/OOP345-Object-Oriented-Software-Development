//Alena Mitrakhovich
//115 297 152
//OOP 345 - Workshop 1
//01/14/2017

#pragma once

using namespace std;
#include <iostream>

namespace w1 {
  const int MAX = 3;
  
  class CString {
    char str[MAX + 1]; //+1 for the \0
  public:
    CString(char* s);
    void display(ostream& os);
  };

  ostream& operator<<(ostream& os, CString& cs);

}