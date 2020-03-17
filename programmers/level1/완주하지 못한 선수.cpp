#include <string>
#include <vector>
#include <map>

using namespace std;

#include <iostream>

string solution(vector<string> participant, vector<string> completion) {
  string answer = "";
  map<string, int> participantMap;
  for (string s : participant) {
    participantMap[s] = participantMap[s] + 1;
  }
  for (string s : completion) {
    participantMap[s] = participantMap[s] - 1;
  }
  for (map<string, int>::iterator it = participantMap.begin(); it != participantMap.end(); it++) {
    if (it->second > 0) {
      answer = it->first;
    }
  }
  return answer;
}

int main() {
  vector<string> vect1;
  vect1.push_back("mislav");
  vect1.push_back("stanko");
  vect1.push_back("mislav");
  vect1.push_back("ana");

  vector<string> vect2;
  vect2.push_back("stanko");
  vect2.push_back("ana");
  vect2.push_back("mislav");

  cout << solution(vect1, vect2) << endl;
}