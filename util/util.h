#ifndef _UTIL_H
#define _UTIL_H 1

#include <iostream>
#include <vector>

#define what_is_name(val) #val

struct depth {
  int value;
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T> &vector) {
  int idx = 0;
  for (const auto &it : vector) {
    if (idx == 0)
      out << "[";
    out << it;
    if (idx < vector.size() - 1)
      out << ", ";
    else
      out << "]";
    idx++;
  }
  return out;
}

std::ostream& operator<<(std::ostream& out, depth d) {
  for (int i = 0; i < d.value; i++) {
    cout << "   ";
  }
  cout << "└- ";
  return cout;
}

#endif