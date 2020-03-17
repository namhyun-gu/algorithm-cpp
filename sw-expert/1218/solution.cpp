#include <iostream>
#include <stack>
using namespace std;

int main(int argc, char* argv[]) {
  freopen("input.txt", "r", stdin);
  for (int test_case = 1; test_case <= 10; test_case++) {
    int length;
    cin >> length;
    char* input = new char[length + 1];
    cin >> input;
    bool valid = false;
    stack<char> s;
    for (int i = 0; i < length; i++) {
      char c = input[i];
      if (c == '(' || c == '{' || c == '[' || c == '<') {
        s.push(c);
      } else {
        char top = s.top();
        if ((top == '(' && c == ')') || (top == '{' && c == '}') ||
            (top == '[' && c == ']') || (top == '<' && c == '>')) {
          s.pop();
        } else {
          break;
        }
      }
    }
    valid = s.empty();
    printf("#%d %d\n", test_case, valid);
  }
  return 0;
}
