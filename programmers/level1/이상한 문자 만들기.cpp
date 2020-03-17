#include <string>
#include <vector>

using namespace std;

vector<string> split_word(string s) {
  vector<string> split;
  int start = 0;
  for (int i = 0; i < s.size(); i++) {
    char c = s[i];
    if (c == ' ' || c == '\0') {
      split.push_back(s.substr(start, i - start));
      start = i + 1;
    }
  }
  split.push_back(s.substr(start, s.size() - start));
  return split;
}

string solution(string s) {
  string answer = "";
  vector<string> split = split_word(s);
  for (int i = 0; i < split.size(); i++) {
    string str = split[i];
    for (int j = 0; j < str.size(); j++) {
      char c = str[j];
      if (j % 2 == 0) {
        answer += (c >= 'a' && c <= 'z') ? c - 32 : c;
      } else {
        answer += (c >= 'A' && c <= 'Z') ? c + 32 : c;
      }
    }
    if (i < split.size() - 1)
      answer += ' ';
  }
  return answer;
}

// 문자열을 단어로 나눌 필요 없이 문자열을 루프할때마다 카운트하고 카운트 값을
// 2의 나머지로 구한 뒤 공백을 만나면 카운트를 초기화하는 방법으로도 구현할 수
// 있음

#include <iostream>
main() {
  cout << (int)'a' << endl;
  cout << (int)'z' << endl;
  cout << (int)'A' << endl;
  cout << (int)'Z' << endl;
  cout << solution("try hello world") << endl;
}