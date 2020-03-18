#include <string>
#include <vector>

using namespace std;

int month[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30};

string solution(int a, int b) {
  string answer = "";
  vector<string> str_day{"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
  int day = 5;
  for (int i = 0; i < a; i++) {
    day += month[i];
  }
  answer = str_day[(day + b - 1) % 7];
  return answer;
}

#include <iostream>

int main() {
  cout << solution(5, 24) << endl;  // "TUE"
}