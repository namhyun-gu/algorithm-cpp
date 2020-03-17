#include <cstring>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
  freopen("test_input.txt", "r", stdin);
  while (!cin.eof()) {
    int test_case, answer = 0;
    char pattern[11];
    char input[1001];
    cin >> test_case;
    cin >> pattern;
    cin >> input;
    int input_length = strlen(input);
    int pattern_length = strlen(pattern);
    int* pattern_skip = new int[pattern_length];
    for (int i = 0; i < pattern_length; ++i) {
      pattern_skip[i] = i;
    }
    int index = pattern_length - 1;
    int pattern_index = index;
    while (index < input_length) {
      if (input[index] == pattern[pattern_index]) {
        if (pattern_index == 0) {
          answer++;
          index += pattern_length;
          pattern_index = pattern_length - 1;
        } else {
          index--;
          pattern_index--;
        }
      } else {
        int skip = pattern_length;
        if (pattern_index == pattern_length - 1) {
          for (int i = 0; i < pattern_length; ++i) {
            if (input[index] == pattern[i]) {
              skip = pattern_skip[pattern_length - 1 - i];
            }
          }
        }
        index += skip;
        pattern_index = pattern_length - 1;
      }
    }
    printf("#%d %d\n", test_case, answer);
  }
  return 0;
}
