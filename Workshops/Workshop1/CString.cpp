//Alena Mitrakhovich
//115 297 152
//OOP 345 - Workshop 1
//01/14/2017

#include "CString.h"
#include <iostream>
#include <cstring>
using namespace std;

namespace w1 {

  CString::CString(char* s) {
    if (s == nullptr) {
      str[0] = '\0';
      return;
    }
    strncpy(str, s, MAX);
    str[MAX] = '\0';
  }

  void CString::display(ostream& os) {
    os << str;
  }

  ostream& operator<<(ostream& os, CString& cs) {
    static int count = 0;
    os << count << ": ";
    count++;

    cs.display(os);
    return os;
  }
} //namespace w1