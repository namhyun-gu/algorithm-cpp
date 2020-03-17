#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
  string answer = "";
  vector<char> chars;
  for (char c : s)
    chars.push_back(c);
  sort(chars.begin(), chars.end(), greater<char>());
  for (char c : chars)
    answer += c;
  return answer;
}

#include <iostream>
main() { cout << solution("Zbcdefg") << endl; }