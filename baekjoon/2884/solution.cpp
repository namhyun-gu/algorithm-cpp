#include <iostream>
using namespace std;

int main() {
  int h, m;
  cin >> h >> m;
  if (m > 45) {
    m -= 45;
  } else {
    if (h == 0)
      h = 23;
    else
      h--;
    m = (m + 60) - 45;
  }
  cout << h << " " << m;
  return 0;
}