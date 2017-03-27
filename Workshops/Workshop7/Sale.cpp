#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

#include "Product.h"
#include "Sale.h"

namespace w7 {
  Sale::Sale(const char* fileName) {
    std::ifstream file(fileName);
    while (file) {
      iProduct* ip = readProduct(file);
      itemList.push_back(ip);
    }
  }

  void Sale::display(std::ostream& os) {
    float total = 0;
    os << "Product No Cost Taxable\n";

    for (auto i : itemList) {
      os << *i;
      total += i->getCharge();
    }
    os << "Total " << total << "\n";
  }

}