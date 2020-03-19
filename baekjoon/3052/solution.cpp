#include <iostream>
using namespace std;

int main() {
  int remain[42] = {0};
  for (int i = 0; i < 10; i++) {
    int tmp;
    cin >> tmp;
    remain[tmp % 42] += 1;
  }
  int cnt = 0;
  for (int i = 0; i < 42; i++) {
    if (remain[i] > 0) cnt++;
  }
  cout << cnt;
  return 0;
}