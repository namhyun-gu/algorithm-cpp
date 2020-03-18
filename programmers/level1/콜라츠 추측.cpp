#include <string>
#include <vector>

using namespace std;

int solution(int num) {
  int answer = 0;
  long n = (long)num;
  while (n != 1) {
    if (answer == 500) break;
    if (n % 2)
      n = n * 3 + 1;
    else
      n /= 2;
    answer++;
  }
  return answer == 500 ? -1 : answer;
}

// long으로 변환해주지 않으면 626331을 구할때 오버플로우가 나서 음수가
// 되기때문에 결과가 488이 나옴.
#include <iostream>
main() {
  cout << solution(6) << endl;       // 8
  cout << solution(16) << endl;      // 4
  cout << solution(626331) << endl;  // -1
}