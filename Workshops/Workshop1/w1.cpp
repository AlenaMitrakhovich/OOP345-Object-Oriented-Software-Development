//Alena Mitrakhovich
//115 297 152
//OOP 345 - Workshop 1
//01/14/2017

#include <iostream>
#include "CString.h"
#include "Process.h"

using namespace std;

int main(int argc, char* argv[]){

  cout << "Command Line : ";
  for (int arg = 0; arg < argc; arg++) {
    cout << " " << argv[arg];
  }
  cout << "\n";

  if (argc == 1) {
    cerr << "Insufficient number of arguments (min 1)\n";
    return 1;
  }

  cout << "Maximum number of characters stored : " << w1::MAX << "\n";

  for (int arg = 1; arg < argc; arg++) {
    process(argv[arg]);
  }

  return 0;
}