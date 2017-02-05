//Alena Mitrakhovich
//115 297 152
//Feb/05/2017
//Workshop4 - OOP345

#pragma once
template<typename K, typename V, int N>
class KVList {
  K k[N];
  V v[N];
  K kDefault;
  V vDefault;
  size_t count;
public:
  KVList() : count(0){
  }// default constructor - adopts a safe empty state

  size_t size() const {
    return count;
  }// returns the number of entires in the key - value list

  const K& key(int i) const {
    if (i >= 0 && i < count)
    return k[i];
    return kDefault;
  }// returns an unmodifiable reference to the key of element i in the list

  const V& value(int i) const {
    if(i >= 0 && i < count)
    return v[i];
    return vDefault;
  } // returns an unmodifiable reference to the value of element i in the list

  KVList& add(const K& kk, const V& vv) {
    if (count < N) {
      v[count] = vv;
      k[count] = kk;
      count++;
    }
    return *this;
  } // adds a new element to the list if room exists and returns a reference to the current object, does nothing if no room exists

  int find(const K& kk) const {
    for (size_t i = 0; i < count; i++)
      if (k[i] == kk)
        return i;
    return -1;
  }// returns the index of the first element in the list with a key equal to k - defaults to 0

  KVList& replace(int i, const K& kk, const V& vv) {
    if (i < count) {
      v[i] = vv;
      k[i] == kk;
    }
    return *this;
  } // replaces element i in the list with the key and value received and returns a reference to the current object

}; //KVList class















 