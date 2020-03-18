#include <string>
#include <vector>

using namespace std;

int calculate_gcd(int a, int b) {
  while (b != 0) {
    int remain = a % b;
    a = b;
    b = remain;
  }
  return a;
}

vector<int> solution(int n, int m) {
  vector<int> answer;
  int gcd = calculate_gcd(n, m);
  answer.push_back(gcd);
  answer.push_back((n * m) / gcd);
  return answer;
}

// GCD = 유클리드 호제법
// - a를 b로 나눈 나머지를 저장함. a에 b를 저장하고, b에 나머지를 저장
// - b가 0이 될때까지 반복
// - a를 반환
// LCM = GCD / (a * b)

#include <iostream>
main() {
  for (auto i : solution(3, 12)) cout << i << " ";
  cout << endl;

  for (auto i : solution(2, 5)) cout << i << " ";
  cout << endl;
}