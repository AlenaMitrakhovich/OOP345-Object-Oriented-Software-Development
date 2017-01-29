//Alena Mitrakhovich
//115 297 152
//OOP 345 - Workshop 3

#include "Text.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

namespace w3 {
  Text::Text(): count(0), lineTable(nullptr) {

  }

  Text::Text(const char* file): count(0), lineTable(nullptr) {
    ifstream in(file);

    if (in.is_open()) {
      string line;
      while (getline(in, line)) {
        count++;
      }
      cout << "Read " << count << " lines\n";
      lineTable = new string[count];
      in.clear();
      in.seekg(0, ios::beg);
      for (size_t line = 0; line < count; line++) {
        getline(in, lineTable[line]);
        auto cr = lineTable[line].find('\r'); //finding the carriage return
        if (cr != string::npos) {
          lineTable[line].erase(cr);
        }
      }
      /*check this*/
      int lines = count;
      if (lines > 10) {
        lines = 10;
      }
      for (int line = 0; line < lines; line++) {
        cout << line + 1 << ": -->" << lineTable[line] << "<--\n";
      }
      in.close();
    }
    else {
      cerr << "Cannot open file '" << file << "'\n";
      exit(3);
    }
  }

  Text::Text(const Text& rhs): count(0), lineTable(nullptr) {
    *this = rhs;
  }//a copy constructor

  Text& Text::operator= (const Text& rhs) {
    if (this != &rhs) {
      delete[] lineTable;
      lineTable = nullptr;
      count = 0;

      count = rhs.count;

      lineTable = new string[count];
      for (size_t i = 0; i < count; i++) {
        lineTable[i] = rhs.lineTable[i];
      }
    }
    return *this;
  }//copy assignment operator

  Text::Text(Text&& rhs) : count(0), lineTable(nullptr) {
    *this = move(rhs);
  } //move constructor

  Text& Text::operator= (Text&& rhs) {
    if (this != &rhs) {
      delete[] lineTable;

      //move pointer+count (steal brains)
      lineTable = rhs.lineTable;
      count = rhs.count;

      //turn rhs into a zombie
      rhs.lineTable = nullptr;
      rhs.count = 0;
    }
    return *this;
  } //move assignment operator


  Text::~Text() {
    if (lineTable) {
      delete[] lineTable;
      lineTable = nullptr;
    }
  }

  size_t Text::size() const {
    return count;
  }

} //namespace w3