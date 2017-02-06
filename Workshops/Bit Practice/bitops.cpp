#include <iostream>
using namespace std;

template<typename T>

bool bittest(T t, int bit) {
  return t & (1 << bit);
}

template<typename T>
void bitprint(T t, int bits) {
  for (int i = bits - 1; i >= 0; i--) {
    cout << "01"[bittest(t, i)];
  }
}

int main() {
  const int BITS = 3;
  for (int i = 0; i < (1 << BITS); i++) {
    bitprint(i, 3);
    cout << "\n";
  }

  cout << "& - AND - ON if both bit ON\n";
  for (int i = 0; i < (1 << BITS); i++) {
    bitprint(i, BITS);
    cout << " : ";
    for (int j = 0; j < BITS; j++) {
      bitprint(i&j, BITS);
      cout << " ";
    }
    cout << "\n";
  }

  cout << "| - OR - ON if either bit ON\n";
  for (int i = 0; i < (1 << BITS); i++) {
    bitprint(i, BITS);
    cout << " : ";
    for (int j = 0; j < BITS; j++) {
      bitprint(i|j, BITS);
      cout << " ";
    }
    cout << "\n";
  }

  cout << "^ - XOR - ON bits are different\n";
  for (int i = 0; i < (1 << BITS); i++) {
    bitprint(i, BITS);
    cout << " : ";
    for (int j = 0; j < BITS; j++) {
      bitprint(i ^ j, BITS);
      cout << " ";
    }
    cout << "\n";
  }
}