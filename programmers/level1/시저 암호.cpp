#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
  string answer = "";
  for (char c : s) {
    if (c >= 'a' && c <= 'z') {
      answer += c + n > 'z' ? 'a' + ((c + n) % 'z') - 1 : c + n;
    } else if (c >= 'A' && c <= 'Z') {
      answer += c + n > 'Z' ? 'A' + ((c + n) % 'Z') - 1 : c + n;
    } else {
      answer += c;
    }
  }
  return answer;
}

#include <iostream>
main() {
  // cout << (int)'a' << endl;
  // cout << (int)'z' << endl;
  // cout << (int)'d' << endl;
  // cout << (int)'A' << endl;
  // cout << (int)'Z' << endl;
  cout << solution("AB", 1) << endl;
  cout << solution("z", 1) << endl;
  cout << solution("a B z", 4) << endl;
}