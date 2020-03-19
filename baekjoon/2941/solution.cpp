#include <iostream>
using namespace std;

int main() {
  char input[101];
  cin >> input;
  int cnt = 0;
  int i = 0;
  while (i < 100) {
    if (input[i] == '\0') break;
    if (input[i] == 'c' && input[i + 1] == '=')
      i += 2;
    else if (input[i] == 'c' && input[i + 1] == '-')
      i += 2;
    else if (input[i] == 'd' && input[i + 1] == 'z' && input[i + 2] == '=')
      i += 3;
    else if (input[i] == 'd' && input[i + 1] == '-')
      i += 2;
    else if (input[i] == 'l' && input[i + 1] == 'j')
      i += 2;
    else if (input[i] == 'n' && input[i + 1] == 'j')
      i += 2;
    else if (input[i] == 's' && input[i + 1] == '=')
      i += 2;
    else if (input[i] == 'z' && input[i + 1] == '=')
      i += 2;
    else
      i++;
    cnt++;
  }
  cout << cnt;
  return 0;
}