#include <bits/stdc++.h>
using namespace std;

int main() {
  int N = 0;
  long result = 0;
  int cnt[101][10];

  cin >> N;

  cnt[1][0] = 0;
  for (int i = 1; i < 10; i++) {
    cnt[1][i] = 1;
  }

  for (int n = 2; n <= N; n++) {
    for (int i = 0; i <= 9; i++) {
      if (i == 0) cnt[n][i] = cnt[n - 1][i + 1];
      else if (i == 9) cnt[n][i] = cnt[n - 1][i - 1];
      else cnt[n][i] = (cnt[n - 1][i - 1] + cnt[n - 1][i + 1]) % 1000000000;
    }
  }
  
  for (int i = 0; i <= 9; i++) {
    result += cnt[N][i];
  }
  cout << result % 1000000000 << endl;
  return 0;
}