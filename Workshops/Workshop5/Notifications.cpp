//Alena Mitrakhovich
//115 297 152
//Workshop 5
//02/12/2017

#include "Notifications.h"
#include <iostream>

using namespace std;
namespace w5 {
  Notifications::Notifications() : messageTable(new Message[MAX_SIZE]), messageCount(0) {
  }//default constructor - empty

  Notifications::Notifications(const Notifications& rhs) : messageTable(nullptr), messageCount(0) {
    messageCount = rhs.messageCount;
    
      for (int i = 0; i < messageCount; i++) {
        messageTable[i] = rhs.messageTable[i];
      }
  
  }//copy constructor

  Notifications& Notifications::operator=(const Notifications& rhs) {
    if (this != &rhs) {
      //delete[] messageTable;
      if (messageTable == nullptr) {
        messageTable = new Message[MAX_SIZE];
      }

      messageCount = rhs.messageCount;

        for (int i = 0; i < messageCount; i++) {
          messageTable[i] = rhs.messageTable[i];
        }
      }
    return *this;
  } //copy assignment operator

  Notifications::Notifications(Notifications&& rhs) : messageTable(rhs.messageTable), messageCount(rhs.messageCount) {

    rhs.messageTable = nullptr;
    rhs.messageCount = 0;
  }//move constructor

  Notifications&& Notifications::operator=(Notifications&& rhs) {
    if (this != &rhs) {
      delete[] messageTable;

      messageTable = rhs.messageTable;
      messageCount = rhs.messageCount;

      rhs.messageTable = nullptr;
      rhs.messageCount = 0;
    }
  return std::move(*this);
  }//move assignment operator

  Notifications::~Notifications() {
    delete[] messageTable;
  }//destructor

  void Notifications::operator+=(const Message& msg) {
    //if (messageTable == nullptr) {
      //messageTable = new Message[MAX_SIZE];
      if (messageCount < MAX_SIZE) {
        messageTable[messageCount] = msg;
        messageCount++;
      }
   // }
  }//adds msg to the set

  void Notifications::display(std::ostream& os) const {
    for (int i = 0; i < messageCount; i++) {
      messageTable[i].display(os);
    }
  }//inserts the Message objects to the os output stream
}