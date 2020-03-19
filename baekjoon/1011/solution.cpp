#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int t, x, y;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> x >> y;
    int ans = 0;
    long dist = y - x;
    long speed;
    for (speed = sqrt(dist); dist > speed * speed; speed++) {
    }
    dist -= speed * speed;
    ans += (speed * 2 - 1) + (long)ceil((double)dist / speed);
    cout << ans << endl;
  }
  return 0;
}
