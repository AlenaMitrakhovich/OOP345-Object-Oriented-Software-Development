#pragma once
#include<iostream>
#include<string>
using namespace std;

class Grades {
  string* studentNum;
  double* gradeNum;
  int count;
public:
  Grades();
  Grades(char* file); 

  Grades(const Grades& other) = delete; //prevent copy constructor
  Grades& operator=(const Grades& other) = delete; //prevent assignment operator
  
  Grades(Grades&& other) = delete; //prevent move constructor
  Grades& operator=(Grades&& other) = delete; //prevent move assignment operator

  ~Grades();

  template<typename letter>
  void displayGrades(std::ostream& os, letter LETTER) const {
    for (int i = 0; i < count; i++) {
      os << studentNum[i] << " " << gradeNum[i] << " " << LETTER(gradeNum[i]) << endl;
    }
  }
}; //class Grades