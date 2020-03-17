#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
  freopen("input.txt", "r", stdin);
  while (!cin.eof()) {
    int test_case, answer;
    int arr[100][100];
    cin >> test_case;
    for (int y = 0; y < 100; ++y) {
      for (int x = 0; x < 100; ++x) {
        cin >> arr[y][x];
      }
    }
    int end_x = 0;
    while (arr[99][end_x] != 2) {
      end_x++;
    }
    int cur_x = end_x;
    int cur_y = 99;
    while (cur_y != 0) {
      if (arr[cur_y][cur_x - 1] == 1 && cur_x != 0) {
        while (arr[cur_y][cur_x - 1] == 1 && cur_x != 0) {
          cur_x--;
        }
      } else if (arr[cur_y][cur_x + 1] == 1 && cur_x != 99) {
        while (arr[cur_y][cur_x + 1] == 1 && cur_x != 99) {
          cur_x++;
        }
      }
      cur_y--;
    }
    answer = cur_x;
    printf("#%d %d\n", test_case, answer);
  }
  return 0;
}
