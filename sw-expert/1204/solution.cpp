#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
  // freopen("input.txt", "r", stdin);
  int T;
  cin >> T;
  for (int test_case = 0; test_case < T; ++test_case) {
    int test_no = 0;
    cin >> test_no;
    int answer;
    int counter[101] = {0};
    for (int i = 0; i < 1000; ++i) {
      int input;
      cin >> input;
      counter[input]++;
    }
    int maxIndex = -1;
    int max = -1;
    for (int i = 0; i < 101; ++i) {
      int val = counter[i];
      if (val >= max) {
        maxIndex = i;
        max = val;
      }
    }
    answer = maxIndex;
    cout << "#" << test_no << " ";
    cout << answer << endl;
  }
  return 0;
}
