//Alena Mitrakhovich
//115 297 152
//amitrakhovich@myseneca.ca

#include <iostream>
#include "string"
#include "fstream"
#include "vector"

using namespace std;

#include "util.h"

class Item;
class ItemManager;

class Item {
  string itemName, itemInstaller, itemRemover, itemSequence, itemDescription;
public:
  Item()
  {

  }

  Item(std::vector<std::string> &row)
  {
    switch (row.size()) {
    case 5:
      itemDescription = row[4];
    case 4:
      if (validItemName(row[0]))
        itemName = row[0];
      else
        throw string("Expected a fail item name, found '") + row[0] + "'";

      if (validTaskName(row[1]))
        itemInstaller = row[1];
      else
        throw string("Expected an installer task name, found '") + row[1] + "'";

      if (validTaskName(row[2]))
        itemRemover = row[2];
      else
        throw string("Expected a remover task name, found '") + row[2] + "'";

      if (validSequence(row[3]))
        itemSequence = row[3];
      else
        throw string("Expected a sequence number, found '") + row[3] + "'";
    
      break;
    default:
      throw string("expected 4 or 5 fields - found ") + to_string(row.size());
    }
  }

  ~Item() {}

  void print()
  {
    cout << "item /name/installer/remover/sequence/description/ = "
      << "/" << itemName
      << "/" << itemInstaller
      << "/" << itemRemover
      << "/" << itemSequence
      << "/" << itemDescription
      << std::endl;
  }

  void graph(fstream& os)
  {
    string q("\"");
    
    os << q +  "Item " + itemName + q + " -> " + q + "Installer " + itemInstaller + q + " [color=green];\n";
    
    os << q + "Item " + itemName + q + " -> " + q + "Remover " + itemRemover + q + " [color=red];\n";
 
  }

}; //class item

class itemManager {
  std::vector<Item> itemList;

public:
  itemManager(std::vector<std::vector<std::string>> &csvData)
  {
    for (auto row : csvData) {
      try {
        itemList.push_back(move(Item(row)));
      }
      catch (std::string& e) {
        cerr << e << std::endl;
      }
    }
  }

  void print()
  {
    for (auto t : itemList)
      t.print();
  }

  void graph(std::string& filename)
  {
    string dotFile = filename + ".gv";
    fstream os(dotFile, std::ios::out | std::ios::trunc);

    os << "digraph itemGraph{\n";

    for (auto t : itemList) {
      t.graph(os);
    }
    os << "}\n";

    os.close();

    string cmd = "dot -Tpng " + filename + ".gv > " + filename + ".gv.png";
    //cout << "running '" << cmd << "'\n";
    system(cmd.c_str());
  }

}; //class itemManager

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