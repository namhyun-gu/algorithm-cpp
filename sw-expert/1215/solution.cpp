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
  for (int test_case = 0; test_case < 10; ++test_case) {
    int search_length, answer = 0;
    cin >> search_length;
    char input[8][9];
    for (int i = 0; i < 8; ++i) {
      cin >> input[i];
    }
    char input_r[8][9] = {0};
    for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < 8; ++j) {
        input_r[i][j] = input[j][i];
      }
    }
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j <= 8 - search_length; j++) {
        if (is_palindrome(&input[i][j], search_length)) {
          answer++;
        }
        if (is_palindrome(&input_r[i][j], search_length)) {
          answer++;
        }
      }
    }
    printf("#%d %d\n", test_case + 1, answer);
  }
  return 0;
}