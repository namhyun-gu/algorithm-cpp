#include <cstring>
#include <iostream>
using namespace std;

bool is_palindrome(char* str, int length) {
  char* substr = new char[length + 1];
  for (int k = 0; k < length; k++) {
    substr[length - k - 1] = str[k];
  }
  substr[length] = '\0';
  int cmp = memcmp(str, substr, length);
  delete substr;
  return cmp == 0;
}

int main(int argc, char* argv[]) {
  freopen("input.txt", "r", stdin);
  for (int test_case = 0; test_case < 10;) {
    cin >> test_case;
    char input[100][101];
    for (int i = 0; i < 100; ++i) {
      cin >> input[i];
    }
    char input_r[100][101] = {0};
    for (int i = 0; i < 100; ++i) {
      for (int j = 0; j < 100; ++j) {
        input_r[i][j] = input[j][i];
      }
    }
    int answer = 2;
    for (int i = 0; i < 100; i++) {
      int length = answer;
      while (length <= 100) {
        bool is_exists = false;
        for (int j = 0; j <= 100 - length && !is_exists; j++) {
          if (is_palindrome(&input[i][j], length)) {
            answer = (answer < length ? length : answer);
          }
          if (is_palindrome(&input_r[i][j], length)) {
            answer = (answer < length ? length : answer);
          }
          if (answer == length) {
            is_exists = true;
          }
        }
        length++;
      }
    }
    printf("#%d %d\n", test_case, answer);
  }
  return 0;
}
