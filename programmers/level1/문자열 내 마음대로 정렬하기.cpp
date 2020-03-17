#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
  vector<string> answer = strings;
  sort(answer.begin(), answer.end(), [n](string a, string b) {
    if (a[n] == b[n])
      return a < b;
    else
      return a[n] < b[n];
  });
  return answer;
}

#include <iostream>

int main() {
  solution(vector<string>{"sun", "bed", "car"}, 1);
  solution(vector<string>{"abce", "abcd", "cdx"}, 2);
}