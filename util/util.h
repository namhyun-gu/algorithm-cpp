#ifndef _UTIL_H
#define _UTIL_H 1

#include <iostream>
#include <vector>

template <typename T>
std::ostream &operator<<(std::ostream& out, const std::vector<T> &vector) {
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

#endif