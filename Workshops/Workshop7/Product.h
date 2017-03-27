//#pragma once
#ifndef _I_PRODUCT_H_
#define _I_PRODUCT_H_

#include <iostream>
#include <fstream>

namespace w7 {

  class iProduct {
  public:
    virtual double getCharge() const = 0;
    virtual void display(std::ostream&) const = 0;
  };

  class Product: public iProduct {
    int prodNum;
    double prodCost;
  public:
    Product(const int num, const double cost);
    double getCharge() const;
    void display(std::ostream&) const;
  };

  class TaxableProduct: public iProduct {
    int prodNum;
    double prodCost;
    char taxed;
  public:
    TaxableProduct(int num, double  cost, char tax);
    double getCharge() const;
    void display(std::ostream&) const;
  };

  std::ostream& operator<<(std::ostream&, const iProduct&);
  iProduct* readProduct(std::ifstream&);

}
#endif