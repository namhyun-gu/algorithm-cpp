#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
  vector<long long> answer;
  long long temp = x;
  for (int i = 0; i < n; i++) {
    answer.push_back(temp);
    temp += x;
  }
  return answer;
}

#include <iostream>
main() {
  for (auto i : solution(2, 5)) cout << i << " ";
  cout << endl;

  for (auto i : solution(4, 3)) cout << i << " ";
  cout << endl;

  for (auto i : solution(-4, 2)) cout << i << " ";
  cout << endl;
}