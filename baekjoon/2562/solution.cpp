#include <iostream>
using namespace std;

int main() {
  int max = -1;
  int maxIndex = 0;
  for (int i = 0; i < 9; i++) {
    int tmp;
    cin >> tmp;
    if (tmp > max) {
      max = tmp;
      maxIndex = i;
    }
  }
  cout << max << "\n" << maxIndex + 1;
  return 0;
}