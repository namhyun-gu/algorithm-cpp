#include <bits/stdc++.h>
using namespace std;

main() {
  int N;
  long long cnt[91][2];
  
  cnt[1][0] = 0;
  cnt[1][1] = 1;

  cin >> N;

  for (int n = 2; n <= N; n++) {
    cnt[n][0] = cnt[n - 1][0] + cnt[n - 1][1];
    cnt[n][1] = cnt[n - 1][0];
  }

  cout << cnt[N][0] + cnt[N][1] << endl;
}
