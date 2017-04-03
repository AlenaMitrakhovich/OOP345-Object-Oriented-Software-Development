//Alena Mitrakhovich
//115 297 152
//amitrakhovich@myseneca.ca

#include <iostream>
#include "string"
#include "fstream"
#include "vector"

//CleanItem.dat
//CleanOrders.dat
//CleanTask.dat
//'|' separator

using namespace std;

#include "util.h"
#include "i.h"
#include "o.h"
#include "t.h"

int main(int argc, char* argv[]) {
  try {
    if (argc != 5)
      throw string("Usage: ") + argv[0] + " item-csv-file order-csv-file task-csv-file csv-separator-character";

    string fileItemName  = argv[1];
    string fileOrderName = argv[2];
    string fileTaskName  = argv[3];
    char separator       = argv[4][0];

    vector<vector<string>> csvItemData;
    vector<vector<string>> csvOrderData;
    vector<vector<string>> csvTaskData;

    csvRead(fileItemName,  separator, csvItemData);
    csvRead(fileOrderName, separator, csvOrderData);
    csvRead(fileTaskName,  separator, csvTaskData);

    //csvPrint(csvItemData);
    //csvPrint(csvOrderData);
    //csvPrint(csvTaskData);

    itemManager  im( csvItemData );
    OrderManager om( csvOrderData);
    TaskManager  tm( csvTaskData );


    bool errors = false;

    if (tm.validate() == false) {
      cerr << "task errors\n";
      errors = true;
    }

    if (im.validate(tm) == false) {
      cerr << "item errors\n";
      errors = true;
    }

    if (om.validate(im) == false) {
      cerr << "order errors\n";
      errors = true;
    }

    im.print();
    im.graph(fileItemName);

    om.print();
    om.graph(fileOrderName);

    tm.print();
    tm.graph(fileTaskName);

    //im.validate(tm);
    //tm.validate();

  }
  catch (const string& e) {
    cerr << e << endl;
  }
}