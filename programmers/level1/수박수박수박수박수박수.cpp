#include <string>
#include <vector>

using namespace std;

string solution(int n) {
  string answer = "";
  for (int i = 0; i < n; i++)
    answer += (i % 2) ? "박" : "수";
  return answer;
}

#include <iostream>
main() {
  cout << solution(3) << endl;
  cout << solution(4) << endl;
}