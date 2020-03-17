#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
  // freopen("input.txt", "r", stdin);
  int test_no = 1;
  while (!cin.eof()) {
    int answer = 0;
    int test_case;
    cin >> test_case;
    int* arr = new int[test_case];
    for (int i = 0; i < test_case; ++i) {
      cin >> arr[i];
    }
    for (int i = 2; i < test_case - 2; i++) {
      int left = (arr[i - 2] > arr[i - 1] ? arr[i - 2] : arr[i - 1]);
      int right = (arr[i + 2] > arr[i + 1] ? arr[i + 2] : arr[i + 1]);
      if (arr[i] > left && arr[i] > right) {
        answer += arr[i] - (left > right ? left : right);
      }
    }
    cout << "#" << test_no << " ";
    cout << answer << endl;
    test_no++;
  }
  return 0;
}
