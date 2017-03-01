// Workshop 6 - Lambda Expression
// w6.cpp

#include <iostream>
#include "Grades.h"
using namespace std;
#include<string.h>
int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << argv[0] <<
      ": incorrect number of arguments\n";
    std::cerr << "Usage: " << argv[0] << " file_name\n";
    return 1;
  }


  Grades grades(argv[1]);

  // define the lambda expression for letter
  auto letter = [](double gradeNum) -> string {
    string LETTER;

    if (gradeNum >= 90 && gradeNum <= 100) {
      LETTER = "A+";
    }
    else if (gradeNum >= 80) {
      LETTER = "A";
    }
    else if (gradeNum >= 75) {
      LETTER = "B+";
    }
    else if (gradeNum >= 70) {
      LETTER = "B";
    }
    else if (gradeNum >= 65) {
      LETTER = "C+";
    }
    else if (gradeNum >= 60) {
      LETTER = "C";
    }
    else if (gradeNum >= 55) {
      LETTER = "D+";
    }
    else if (gradeNum >= 50) {
      LETTER = "D";
    }
    else {
      LETTER = "F";
    }

    return LETTER;
  };

  grades.displayGrades(std::cout, letter);

  std::cout << "Press any key to continue ... ";
  std::cin.get();
}