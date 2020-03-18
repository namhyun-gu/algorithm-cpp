#include <string>
#include <vector>

using namespace std;

string solution(string s) {
  string answer = "";
  if (s.size() % 2) {
    answer = s[s.size() / 2];
  } else {
    answer = s.substr((s.size() / 2) - 1, 2);
  }
  return answer;
}

#include <iostream>

int main() {
  cout << solution("abcde") << endl;  // "c"
  cout << solution("qwer") << endl;   // "we"
}