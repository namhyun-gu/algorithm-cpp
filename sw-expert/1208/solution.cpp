#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
  // freopen("input.txt", "r", stdin);
  int test_no = 1;
  while (!cin.eof()) {
    int dump;
    cin >> dump;
    int counter[101] = {0};
    for (int i = 0; i < 100; ++i) {
      int input;
      cin >> input;
      counter[input]++;
    }
    int left, right;
    for (int j = 0; j < dump; ++j) {
      left = 0;
      right = 0;
      for (int index = 0; left == 0 || right == 0; index++) {
        if (left == 0 && counter[index] > 0) left = index;
        if (right == 0 && counter[100 - index] > 0) right = 100 - index;
      }
      counter[left]--;
      counter[left + 1]++;
      counter[right]--;
      counter[right - 1]++;
    }
    left = 0;
    right = 0;
    for (int index = 0; left == 0 || right == 0; index++) {
      if (left == 0 && counter[index] > 0) left = index;
      if (right == 0 && counter[100 - index] > 0) right = 100 - index;
    }
    int answer = right - left;
    cout << "#" << test_no << " ";
    cout << answer << endl;
    test_no++;
  }
  return 0;
}
