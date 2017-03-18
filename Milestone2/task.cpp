//Alena Mitrakhovich
//115 297 152
//amitrakhovich@myseneca.ca

#include <iostream>
#include "string"
#include "fstream"
#include "vector"

using namespace std;

#include "util.h"

class Task;
class TaskManager;

class Task {
  string taskName, taskSlots, taskPass, taskFail;
public:
  Task() : taskSlots("1")
  {

  }

  Task(std::vector<std::string> &row) : taskSlots("1")
  {
    switch (row.size()) {
    case 4:
      if (validTaskName(row[3]))
        taskFail = row[3];
      else
        throw string("Expected a fail task name, found '") + row[3] + "'";
    case 3:
      if (validTaskName(row[2]))
        taskPass = row[2];
      else
        throw string("Expected a fail task name, found '") + row[2] + "'";
    case 2:
      if (validSlots(row[1]))
        taskSlots = row[1];
      else
        throw string("Expected a slot, found '") + row[1] + "'";
    case 1:
      if (validTaskName(row[0]))
        taskName = row[0];
      else
        throw string("Expected a fail task name, found '") + row[0] + "'";
      break;
    default:
      throw string("expected 1,2,3, or 4 fields - found ") + to_string(row.size());
    }
  }

  ~Task() {}

  void print() 
  {
    cout << "task /name/slots/pass/fail/ = "
      << "/" << taskName
      << "/" << taskSlots
      << "/" << taskPass
      << "/" << taskFail
      << std::endl;
  }

  void graph(fstream& os)
  {
    if (!taskFail.empty()) {
      os << '"' << taskName + "\" -> \"" + taskFail + "\"[color=red];\n";
    }
    if (!taskPass.empty()) {
      os << '"' << taskName + "\" -> \"" + taskPass + "\"[color=green];\n";
    }
    if (taskFail.empty() && taskPass.empty()) {		//isolated node
      os << '"' << taskName + "\";\n";
    }
  }

}; //class Task

class TaskManager {
  std::vector<Task> taskList;

public:
  TaskManager(std::vector<std::vector<std::string>> &csvData) 
  {
    for (auto row : csvData){
      try {
        taskList.push_back(move(Task(row)));
      } catch (std::string& e) {
          cerr << e << std::endl;
      }
    }
  }

  void print() 
  {
    for (auto t : taskList)
      t.print();
  }

  void graph(std::string& filename)
  {
    string dotFile = filename + ".gv";
    fstream os(dotFile, std::ios::out | std::ios::trunc);

    os << "digraph taskGraph{\n";

    for (auto t : taskList) {
      t.graph(os);
    }
    os << "}\n";

    os.close();

    string cmd = "dot -Tpng " + filename + ".gv > " + filename + ".gv.png";
    system(cmd.c_str());
  }

}; //class TaskManager

int main(int argc, char* argv[]) {
  try {
    if (argc != 3)
      throw string("Usage: ") + argv[0] + " csv-data-file csv-separator-character";
    string fileName = argv[1];
    char separator = argv[2][0];

    vector<vector<string>> csvData;
    csvRead(fileName, separator, csvData);
    //csvPrint(csvData);

    TaskManager tm(csvData);
    tm.print();
    tm.graph(fileName);

  }
  catch (const string& e) {
    cerr << e << endl;
  }
}