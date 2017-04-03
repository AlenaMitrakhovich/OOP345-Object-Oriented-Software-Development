//Alena Mitrakhovich
//115 297 152
//amitrakhovich@myseneca.ca

#include <iostream>
#include "string"
#include "fstream"
#include "vector"

using namespace std;

#include "util.h"
#include "i.h"

int main(int argc, char* argv[]) {
  try {
    if (argc != 3)
      throw string("Usage: ") + argv[0] + " csv-data-file csv-separator-character";
    string fileName = argv[1];
    char separator = argv[2][0];

    vector<vector<string>> csvData;
    csvRead(fileName, separator, csvData);
    //csvPrint(csvData);

    itemManager im(csvData);
    im.print();
    im.graph(fileName);

  }
  catch (const string& e) {
    cerr << e << endl;
  }
}