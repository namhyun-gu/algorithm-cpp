#include <iostream>
using namespace std;

// https://blog.naver.com/djm03178/221253402146

int main() {
  int n, a, b;
  cin >> n;

  int ans = -1;
  for (a = 0; a * 5 <= n; a++) {
    for (b = 0; a * 5 + b * 3 <= n; b++) {
      if (a * 5 + b * 3 == n) ans = a + b;
    }
  }
  cout << ans;
  return 0;
}