#include <string>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

vector<int> solution(int brown, int red) {
  for (int h = 3; h <= red + 2; h++)
    for (int w = h; (w * 2) + ((h * 2) - 4) <= brown; w++)
      if (red == (w - 2) * (h - 2))
        return {w, h};
  return {0, 0};
}

#include <iostream>
#include "../../util/util.h"

main() {
  cout << solution(10, 2) << endl; //	[4, 3]
  cout << solution(8, 1) << endl; // [3, 3]
  cout << solution(24, 24) << endl; // [8, 6]
  cout << solution(81344, 1000000) << endl; // [1056, 1024]
  cout << solution(18, 6) << endl; // [8, 3]
}