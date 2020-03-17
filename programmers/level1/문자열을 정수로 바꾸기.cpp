#include <string>
#include <vector>

using namespace std;

int solution(string s) {
  int answer = atoi(s.c_str());
  return answer;
}

#include <iostream>
main() {
  cout << solution("1234") << endl;
  cout << solution("-1234") << endl;
}