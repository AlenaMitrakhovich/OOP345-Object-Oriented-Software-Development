#include "X.h"
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
  X<int> a; //default constructor
  a.print(); 

  X<int> b(50000); //argument constructor
  b.print(); 

  X<int> c = b; //copy constructor using assignment operator
  c.print(); 

  c = a; //assignment operator
  c.print();

  X<int> d(std::move(b)); //move constructor
  d.print(); //now has 50000
  b.print(); //became a zombie

  X<int> e(75000);
  e.print();
  b = std::move(e); //move assignment
  b.print(); //now has 75000
  e.print(); //became a zombie
}