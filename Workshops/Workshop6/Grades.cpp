#include "Grades.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

Grades::Grades(): studentNum(nullptr), gradeNum(nullptr), count(0) {

}

Grades::~Grades() {
  delete[] studentNum;
  delete[] gradeNum;
}

Grades::Grades(char* file) {
  try {
    fstream myfile(file);
    
    if (!myfile.is_open()) {
      throw 99;
    }

    if (myfile.is_open()) {
        string tempStr;
        int tempCount = 0;
        while (getline(myfile, tempStr, '\n')) {
          tempCount++;
        }

        myfile.clear();
        myfile.seekg(0);

        count = tempCount;
        studentNum = new string[count];
        gradeNum = new double[count];

        for (int i = 0; i < count; i++) {
          //easier way:
          //myfile >> studentNum[i];
          //myfile >> gradeNum[i];

          //using getline:
          getline(myfile, studentNum[i], ' ');
          
          getline(myfile, tempStr, '\n');
          gradeNum[i] = stod(tempStr);
        }

        myfile.close();
    }
  }

  catch (int x) {
    cout << "Problem encountered opening the file(error:" << x << ")" << endl;
  }
}