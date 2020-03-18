#include <string>

using namespace std;

struct _stage {
  int point;
  char bonus;
  char option;
  int result;
} typedef stage;

int solution(string dartResult) {
  int answer = 0;
  int stage_idx = 0;
  stage stages[3];
  stage temp;
  for (int i = 0; i < dartResult.size(); i++) {
    char c = dartResult[i];
    if (c >= '0' && c <= '9') {
      temp = stage();
      if (c == '1' && dartResult[i + 1] == '0') {
        temp.point = 10;
        i++;
      } else {
        temp.point = c - '0';
      }
    }
    if (c == 'S' || c == 'D' || c == 'T') {
      temp.bonus = c;
      stages[stage_idx++] = temp;
    }
    if (c == '*' || c == '#') {
      stages[stage_idx - 1].option = c;
    }
  }
  for (int i = 0; i < 3; i++) {
    stage *s = &stages[i];
    int point = s->point;
    if (s->bonus == 'D')
      point *= point;
    else if (s->bonus == 'T')
      point *= point * point;
    if (s->option == '*') {
      point *= 2;
      if (i > 0) {
        stages[i - 1].result *= 2;
      }
    } else if (s->option == '#') {
      point *= -1;
    }
    s->result = point;
  }
  for (stage s : stages) answer += s.result;
  return answer;
}

#include <iostream>
main() {
  cout << solution("1S2D*3T") << endl;   // 37
  cout << solution("1D2S#10S") << endl;  // 9
  cout << solution("1D2S0T") << endl;    // 3
  cout << solution("1S*2T*3S") << endl;  // 23
  cout << solution("1D#2S*3S") << endl;  // 5
  cout << solution("1T2D3D#") << endl;   // -4
  cout << solution("1D2S3T*") << endl;   // 59
}