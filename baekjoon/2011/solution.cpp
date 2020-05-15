#include<bits/stdc++.h>
using namespace std;

int main() {
  int cases[5001] = {1, 1};
  string s;

  getline(cin, s);

  for (int i = 2; i <= s.length(); i++) {
    char cur = s[i - 1];
    char prev = s[i - 2];
    int num = (prev - '0') * 10 + (cur - '0');

    if (cur > '0') {
      cases[i] = cases[i - 1];
    }
    if (num >= 10 && num <= 26) {
      cases[i] = (cases[i] + cases[i - 2]) % 1000000;
    }
  }
  if (s[0] == '0') {
    cout << 0 << '\n';
  } else {
    cout << cases[s.length()] << '\n';
  }
}
