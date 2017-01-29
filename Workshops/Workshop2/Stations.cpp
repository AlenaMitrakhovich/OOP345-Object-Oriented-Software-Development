//Alena Mitrakhovich
//115 297 152
//Workshop 2
//01/21/2017

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

#include "Stations.h"

using namespace std;

namespace w2 {

  Stations::Stations(char* f) {

    fstream is(f, ios::in);

    if (is.is_open()) {
      is >> stationCount;
     
      char semicolon;
      is.get(semicolon);
      if (semicolon != ';') {
        std::cerr << "No ';' found - found: '" << semicolon << "'\n";
        exit(1);
      }

      stationTable = new Station[stationCount];
      for (int s = 0; s < stationCount; s++) {
        stationTable[s] = Station(is);
      }
      is.close();
    }
    else {
      cerr << "cannot open file '" << f << "'\n";
      exit(8);
    }
  }

  Stations::~Stations() {

    if (stationTable) {
      delete[] stationTable;
      stationTable = nullptr;
    }

  }

  void Stations::restock() {
    cout << "\nPasses Added :\n";
    cout << "--------------\n";
    int student;
    int adult;

    for (int s = 0; s < stationCount; s++) {
      cout << stationTable[s].getName() << "\n";
      cout << " Student Passes added : ";
      cin >> student;
      cout << " Adult   Passes added : ";
      cin >> adult;

      stationTable[s].update(PASS_STUDENT, student);
      stationTable[s].update(PASS_ADULT, adult);
    }
  }

  void Stations::update() {
    cout << "\npasses Sold :\n";
    cout << "-------------\n";
    int student;
    int adult;

    for (int s = 0; s < stationCount; s++) {
      cout << stationTable[s].getName() << "\n";
      cout << " Student Passes sold : ";
      cin >> student;
      cout << " Adult   Passes sold : ";
      cin >> adult;

      stationTable[s].update(PASS_STUDENT, -student);
      stationTable[s].update(PASS_ADULT, -adult);
    }
  }

  void Stations::report() {

    cout << "\nPasses in Stock : Student Adult\n";
    cout << "-------------------------------\n";

    for (int s = 0; s < stationCount; s++) {
      cout << left << setw(19) << stationTable[s].getName();
      cout << right << setw(8) << stationTable[s].inStock(PASS_STUDENT);
      cout << right << setw(6) << stationTable[s].inStock(PASS_ADULT);
    }
    cout << "\n";
  }

} //namespace w2