#include <algorithm>
#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
  long long answer = 0;
  vector<int> digits;
  while (n != 0) {
    digits.push_back(n % 10);
    n /= 10;
  }
  sort(digits.begin(), digits.end());
  int idx = 1;
  for (int digit : digits) {
    answer += digit * idx;
    idx *= 10;
  }
  return answer;
}

#include <iostream>
main() { cout << solution(118372) << endl; }