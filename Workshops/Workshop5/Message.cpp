//Alena Mitrakhovich
//115 297 152
//Workshop 5
//02/12/2017

#include "Message.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
namespace w5 {
  Message::Message(std::ifstream& in, char c) {
    string line;
    getline(in, line, c);

    auto cr = line.find('\r');
    if (cr != std::string::npos)
      line.erase(cr);
    //cout << "line -->" << line << "<--\n";

    size_t index = 0;

    while (index < line.size() && line[index] != ' ') {
      //if (line[index] == ' ') break;
      name += line[index];
      index++;
    }
    //cout << "name = '" << name << "'\n";

    //cout << "line[index] = '" << line[index] << "'\n";
    index++; //skip the ' '

    if (index < line.size() && line[index] == '@') { //if we have a @reply field
      index++; //skip the @
      while (index < line.size() && line[index] != ' ') {
        //if (line[index] == ' ') break;
        reply += line[index];
        index++;
      }
      //cout << "reply = '" << reply << "'\n";
      //index++; //skipe the ' '
    }
    while (index < line.size()) {
      tweet += line[index];
      index++;
    }
    //cout << "tweet = '" << tweet << "'\n";
  }//constructor retrieves a record from the in file object, parses the record(as described above) and stores its components in the Message object.c is the character that delimits each record
  
  bool Message::empty() const {
    return tweet.empty();
  }//returns true if the object is in a safe empty state

  void Message::display(std::ostream& os) const {
    os << "Message\n";
    os << "User  : " << name << "\n";
    if (!reply.empty()) {
      os << "Reply : " << reply << "\n";
      os << "Tweet : " << tweet << "\n";
    }
    else {
      os << "Tweet : " << tweet << "\n";
      os << "\n";
    }
  }//displays the Message objects within the container
}