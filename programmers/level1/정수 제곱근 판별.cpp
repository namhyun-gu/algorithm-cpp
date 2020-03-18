#include <cmath>
#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
  long long answer = 0;
  double i = sqrt(n);
  if ((i - (int)i) == 0)
    answer += pow(i + 1, 2);
  else
    answer = -1;
  return answer;
}

#include <iostream>
main() {
  cout << solution(121) << endl;  // 144
  cout << solution(3) << endl;    // -1
}