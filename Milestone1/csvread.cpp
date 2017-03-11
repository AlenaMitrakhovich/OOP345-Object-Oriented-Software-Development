//Alena Mitrakhovich
//115 297 152
//amitrakhovich@myseneca.ca

#include <iostream>
#include "string"
#include "fstream"
#include "vector"

using namespace std;

void trim(string& s) {
  while (!s.empty() && s[0] == ' ') {
    s.erase(0, 1); //delete 1st character
  }
  while (!s.empty() && s[s.size() - 1] == ' ') {
    s.erase(s.size() - 1, 1); //delete last character
  }
}

void csvRead(string& fileName, char separator, vector< vector<string> > &csvData) {

  fstream is(fileName, ios::in);
  if (!is.is_open())
    throw string("Cannot open file '") + fileName + "'";

  string line;


  while (getline(is, line)) {

    auto cr = line.find('\r');
    if (cr != string::npos)
      line.erase(cr);

    //cout << line << endl;

    string field;
    size_t index = 0;
    vector<string> fields;

    while (index < line.size()) {

      while (index < line.size() && line[index] != separator) {
        field += line[index];
        index++;
      }
      //cout << field << endl;
      index++;//skip separator

      trim(field); //get rid of spaces
      fields.push_back(move(field));
    }
    for (auto e : fields)
      cout << "[" << e << "] ";
    cout << endl;

    csvData.push_back(move(fields));
  }

  is.close();


}

void csvPrint(vector<vector<string>> &csvData) {
  for (auto row : csvData) {
    for (auto column : row) {
      cout << "<" << column << "> ";
    }
    cout << endl;
  }

  for (auto row = csvData.begin(); row != csvData.end(); row++) {
    for (auto column = row->begin(); column != row->end(); column++) {
      cout << "[" << *column << "] ";
    }
    cout << endl;
  }

  for (size_t row = 0; row < csvData.size(); row++) {
    for (size_t column = 0; column < csvData[row].size(); column++) {
      cout << "{" << csvData[row][column] << "} ";
    }
    cout << endl;
  }
}


int main(int argc, char* argv[]) {
  try {
    if (argc != 3)
      throw string("Usage: ") + argv[0] + " csv-data-file csv-separator-character";
    string fileName = argv[1];
    char separator = argv[2][0];

    vector<vector<string>> csvData;
    csvRead(fileName, separator, csvData);
    csvPrint(csvData);
  }
  catch (const string& e) {
    cerr << e << endl;
  }
}