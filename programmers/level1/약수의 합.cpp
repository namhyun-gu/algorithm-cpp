#include <string>
#include <vector>

using namespace std;

int solution(int n) {
  int answer = 0;
  for (int i = 1; i <= n; i++) {
    if (n % i == 0)
      answer += i;
  }
  return answer;
}

#include <iostream>
main() {
  cout << solution(0) << endl;
  cout << solution(1) << endl;
  cout << solution(12) << endl; // 28
  cout << solution(5) << endl;  // 6
}