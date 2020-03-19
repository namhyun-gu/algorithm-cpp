#include <iostream>
using namespace std;

inline int pow(int x, int y) {
  if (y == 0) return 1;
  int result = x;
  for (int i = 1; i < y; i++) result *= x;
  return result;
}

int main() {
  int a, sum = 0;
  char b[4];
  cin >> a >> b;
  for (int i = 0; i < 3; i++) {
    int tmp = (b[2 - i] - 48);
    int mul = a * tmp;
    cout << mul << endl;
    int tmp2 = mul * pow(10, i);
    sum += tmp2;
  }
  cout << sum << endl;
  return 0;
}