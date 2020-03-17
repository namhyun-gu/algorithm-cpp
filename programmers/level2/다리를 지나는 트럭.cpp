#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
  int answer = 0;
  int trucks = truck_weights.size();
  int bridge_weight = 0;
  queue<pair<int, int>> on_bridge_trucks;
  vector<int> moved_trucks;
  for (answer = 1; moved_trucks.size() < trucks; answer++) {
    if (!truck_weights.empty()) {
      int truck_weight = truck_weights.front();
      if (bridge_weight + truck_weight <= weight) {
        on_bridge_trucks.push(make_pair(truck_weight, answer));
        truck_weights.erase(truck_weights.begin());
        bridge_weight += truck_weight;
      }
    }
    pair<int, int> front_truck = on_bridge_trucks.front();
    if (answer - front_truck.second == bridge_length - 1) {
      bridge_weight -= front_truck.first;
      moved_trucks.push_back(front_truck.first);
      on_bridge_trucks.pop();
    }
  }
  return answer;
}

#include <iostream>
main() {
  cout << solution(2, 10, vector<int>{7, 4, 5, 6}) << endl; // 8
  cout << solution(100, 100, vector<int>{10}) << endl;      // 101
  cout << solution(100, 100,
                   vector<int>{10, 10, 10, 10, 10, 10, 10, 10, 10, 10})
       << endl; // 110
}