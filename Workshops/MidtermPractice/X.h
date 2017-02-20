#pragma once
#include <iostream>
using namespace std;

template <class T>

class X {
  size_t size;
  T* data;
public:
  X(): size(0), data(nullptr){
    cout << "Default constructor called" << endl;
  } //default constructor, safe empty state

  X(size_t size): size(size), data(new T[size]){
    cout << "Argument constructor called" << endl;
  } //constructor 

  ~X() {
    if (data) {
      delete[] data;
    }
    cout << "Destructor called" << endl;
  } //destructor

  void print() const {
    cout << "size: " << size;
    if (size > 0) {
      cout << " has brains" << endl;
    }
    else {
      cout << " is a zombie" << endl;
    }
  } //print function

  X(const X& other): size(0), data(nullptr) {

    *this = other;
    cout << "Copy constructor called" << endl;
  } //copy constructor

  X& operator=(const X& other) {
    if (this != &other) {
      if (data) {
        delete[] data;
      }
      size = other.size;
      data = new T[size];
      for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
      }
    }
    cout << "Assignment operator called" << endl;
    return *this;
  } //assignment operator

  X(X&& other): size(other.size), data(other.data) {
    other.size = 0;
    other.data = nullptr;

    cout << "Move constructor called" << endl;
  }//move constructor

  X& operator=(X&& other) {
    if (this != &other) {
      if (data) {
        delete[] data;
      }
      size = other.size;
      data = other.data;
      other.size = 0;
      other.data = nullptr;
    }
    cout << "Move assignment called" << endl;
    return std::move(*this);
  }//move assignment

}; //class X