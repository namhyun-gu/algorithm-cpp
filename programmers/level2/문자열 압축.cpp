#include <string>
#include <vector>

using namespace std;

vector<string> slice(string s, int length) {
  vector<string> v;
  for (int i = 0; i < s.size(); i += length)
    v.push_back(s.substr(i, length));
  return v;
}

string compress(vector<string> v) {
  string result = "";
  vector<string> list;
  for (string s : v) {
    if (list.empty() || s.compare(list.back()) == 0) {
      list.push_back(s);
    } else {
      int cnt = list.size();
      if (cnt > 1) result.append(to_string(cnt) + list.back());
      else result.append(list.back());
      list.clear();
      list.push_back(s);
    }
  }
  int cnt = list.size();
  if (cnt > 1) result.append(to_string(cnt) + list.back());
  else result.append(list.back());
  return result;
}

int solution(string s) {
    int answer = s.size();
    for (int i = 1; i < s.size(); i++) {
      vector<string> v = slice(s, i);
      string compreess_result = compress(v);
      int tmp = compreess_result.size();
      if (tmp < answer) answer = tmp;
    }
    return answer;
}

#include <iostream>

int main() {
  cout << solution("aabbaccc") << endl;
  cout << solution("ababcdcdababcdcd") << endl;
  cout << solution("abcabcdede") << endl;
  cout << solution("abcabcabcabcdededededede") << endl;
  cout << solution("xababcdcdababcdcd") << endl;
}