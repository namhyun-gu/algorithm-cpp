#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
  int n = x;
  int digit = 0;
  while (n != 0) {
    digit += n % 10;
    n /= 10;
  }
  return x % digit == 0;
}

#include <iostream>
main() {
  cout << solution(10) << endl;  // true
  cout << solution(12) << endl;  // true
  cout << solution(11) << endl;  // false
  cout << solution(13) << endl;  // false
}