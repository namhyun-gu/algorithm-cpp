#include <string>
#include <vector>

using namespace std;

string solution(int num) { return num % 2 == 0 ? "Even" : "Odd"; }

#include <iostream>
main() {
  cout << solution(3) << endl;  // Odd
  cout << solution(4) << endl;  // Even
}