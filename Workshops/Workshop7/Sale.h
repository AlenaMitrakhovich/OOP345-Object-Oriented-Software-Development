#pragma once
#include <iostream>
#include <vector>

#include "Product.h"

namespace w7 {

  class Sale {
    std::vector<iProduct*> itemList;
  public:
    Sale(const char*);
    void display(std::ostream&);
  };

}