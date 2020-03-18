#include <iostream>

using namespace std;
int solution(int n) {
  int answer = 0;
  while (n != 0) {
    int digit = n % 10;
    answer += digit;
    n /= 10;
  }
  return answer;
}

#include <iostream>
main() {
  cout << solution(123) << endl;  // 6
  cout << solution(987) << endl;  // 24
}