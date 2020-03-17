#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
  long long answer = 0;
  if (a == b)
    answer = a;
  else {
    long long s, e, sum = 0;
    s = a < b ? a : b;
    e = a < b ? b : a;
    for (long long i = s; i <= e; i++)
      sum += i;
    answer = sum;
  }
  return answer;
}

#include <iostream>

int main() {
  cout << solution(3, 5) << endl;
  cout << solution(3, 3) << endl;
  cout << solution(5, 3) << endl;
}