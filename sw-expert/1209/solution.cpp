#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
  freopen("input.txt", "r", stdin);
  int test_no;
  while (!cin.eof()) {
    cin >> test_no;
    int sum[202] = {0};
    for (int y = 0; y < 100; ++y) {
      for (int x = 0; x < 100; ++x) {
        int input;
        cin >> input;
        if (x == y) {
          sum[200] += input;
        }
        if (x == 100 - y) {
          sum[201] += input;
        }
        sum[x] += input;
        sum[100 + y] += input;
      }
    }
    int max = -1;
    for (int i = 0; i < 202; ++i) {
      if (sum[i] > max) {
        max = sum[i];
      }
    }
    int answer = max;
    cout << "#" << test_no << " ";
    cout << answer << endl;
  }
  return 0;
}
