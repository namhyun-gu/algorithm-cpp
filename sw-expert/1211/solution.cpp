#include <climits>
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
    int lengths[100] = {0};
    for (int end_x = 0; end_x < 100; ++end_x) {
      if (arr[99][end_x] > 0) {
        int length = 0;
        int cur_x = end_x;
        int cur_y = 99;
        while (cur_y != 0) {
          if (arr[cur_y][cur_x - 1] == 1 && cur_x != 0) {
            while (arr[cur_y][cur_x - 1] == 1 && cur_x != 0) {
              cur_x--;
              length++;
            }
          } else if (arr[cur_y][cur_x + 1] == 1 && cur_x != 99) {
            while (arr[cur_y][cur_x + 1] == 1 && cur_x != 99) {
              cur_x++;
              length++;
            }
          }
          cur_y--;
          length++;
        }
        lengths[cur_x] = length;
      }
    }
    int min = INT_MAX;
    for (int i = 0; i < 100; ++i) {
      if (lengths[i] < min && lengths[i] != 0) {
        min = lengths[i];
        answer = i;
      }
    }
    printf("#%d %d\n", test_case, answer);
  }
  return 0;
}
