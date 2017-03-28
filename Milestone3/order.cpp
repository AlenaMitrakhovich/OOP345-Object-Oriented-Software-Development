//Alena Mitrakhovich
//115 297 152
//amitrakhovich@myseneca.ca

#include <iostream>
#include "string"
#include "fstream"
#include "vector"

using namespace std;

#include "util.h"

class Order;
class OrderManager;

class Order {
  string orderCustomer, orderProduct;
  vector<string> itemList;
public:
  Order()
  {

  }

  Order(std::vector<std::string> &row)
  {
    if (row.size() < 3)
      throw string("Expected at least 3 field - found ") + to_string(row.size());

    if (validCustomerName(row[0]))
      orderCustomer = row[0];
    else
      throw string("Expected a customer name - found '") + row[0] + "'";

    if (validOrderName(row[1]))
      orderProduct = row[1];
    else
      throw string("Expected a product name - found '") + row[1] + "'";

    for (size_t i = 2; i < row.size(); i++)
      if (validItemName(row[i]))
        itemList.push_back(row[i]);
  }

  ~Order() {}

  void print()
  {
    cout << "order/customer/product/items.../ = "
      << "/" << orderCustomer
      << "/" << orderProduct;
      
    for (auto item : itemList)
      cout << "/" << item;

    cout << endl;
  }

  void graph(fstream& os)
  {
    string q("\"");
    for (auto item : itemList)
    os << q + orderCustomer + ":" + orderProduct + q + " -> " + q + item + q + " [color=blue];\n";

  }

}; //class order

class OrderManager {
  std::vector<Order> orderList;

public:
  OrderManager(std::vector<std::vector<std::string>> &csvData)
  {
    for (auto row : csvData) {
      try {
        orderList.push_back(move(Order(row)));
      }
      catch (std::string& e) {
        cerr << e << std::endl;
      }
    }
  }

  void print()
  {
    for (auto t : orderList)
      t.print();
  }

  void graph(std::string& filename)
  {
    string dotFile = filename + ".gv";
    fstream os(dotFile, std::ios::out | std::ios::trunc);

    os << "digraph orderGraph{\n";

    for (auto t : orderList) {
      t.graph(os);
    }
    os << "}\n";

    os.close();

    string cmd = "dot -Tpng " + filename + ".gv > " + filename + ".gv.png";
    //cout << "running '" << cmd << "'\n";
    system(cmd.c_str());
  }

}; //class orderManager

int main(int argc, char* argv[]) {
  try {
    if (argc != 3)
      throw string("Usage: ") + argv[0] + " csv-data-file csv-separator-character";
    string fileName = argv[1];
    char separator = argv[2][0];

    vector<vector<string>> csvData;
    csvRead(fileName, separator, csvData);
    //csvPrint(csvData);

    OrderManager om(csvData);
    om.print();
    om.graph(fileName);

  }
  catch (const string& e) {
    cerr << e << endl;
  }
}