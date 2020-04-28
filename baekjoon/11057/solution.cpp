#include <bits/stdc++.h>
using namespace std;

main() {
  int n;
  int cnt[1001][10];

  cin >> n;

  for (int i = 0; i < 10; i++) {
    cnt[1][i] = 1;
  }

  for (int l = 2; l <= n; l++) {
    for (int i = 0; i < 10; i++) {
      cnt[l][i] = 0;
      for (int j = i; j < 10; j++) {
        cnt[l][i] += cnt[l - 1][j] % 10007;
      }
    }
  }

  int result = 0;
  for (int i = 0; i < 10; i++) {
    result += cnt[n][i];
  }
  cout << result % 10007 << endl;
}
