#include "Product.h"
#include <iostream>
#include <fstream>

using namespace std;
namespace w7 {
  Product::Product(const int num, const double cost) {
    prodNum = num;
    prodCost = cost;
  }

  double Product::getCharge() const {
    return prodCost;
  }

  void Product::display(std::ostream& os) const {
    os << prodNum << ", " << prodCost << endl;
  }

  TaxableProduct::TaxableProduct(int num, double  cost, char tax) {
    prodNum = num;
    prodCost = cost;
    taxed = tax;
  }

  double TaxableProduct::getCharge() const {
    double rate = 1;
    if (taxed == 'H') 
      rate = 1.13;
    if (taxed == 'P') 
      rate = 1.08;
    return (prodCost * rate);
  }

  void TaxableProduct::display(std::ostream& os) const {
    os << prodNum << ", " << prodCost << ' ';
    if (taxed == 'H') 
      os << "HST";
    if (taxed == 'P') 
      os << "PST";
    os << "\n";
  }

  std::ostream& operator<<(std::ostream& os, const iProduct& i) {
    i.display(os);
    return os;
  }

  iProduct* readProduct(std::ifstream& is) {
    int num;
    double cost;
    char tax;

    iProduct* temp;

    is >> num >> cost;
    if (is.get() != '\n') {
      is.get(tax);
      temp = new TaxableProduct(num, cost, tax);
    }
    else temp = new Product(num, cost);
    return temp;
  }
}