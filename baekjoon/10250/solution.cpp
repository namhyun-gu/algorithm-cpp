#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int t, h, w, n;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> h >> w >> n;
    int n_w = ceil((double)n / h);
    int n_h = n % h;
    if (n_h == 0)
      cout << h;
    else
      cout << n_h;
    printf("%02d\n", n_w);
  }
  return 0;
}