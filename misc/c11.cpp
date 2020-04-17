#include <bits/stdc++.h>
using namespace std;

// Reference : https://www.acmicpc.net/blog/view/10
// #1. STL 선언
void stl_define_example() { vector<pair<int, int>> stl_vector; }

struct Point {
  double x, y;
  Point(double x, double y) : x(x), y(y) {}
};

// #2. Initalizer Lists
void initalizer_lists_example() {
  vector<int> primes = {2, 3, 5, 7};
  pair<string, int> p = {"Year", 2020};
  map<string, int> age = {{"Saerom", 24}, {"Hayoung", 24}};
  vector<vector<int>> matrix = {{1, 2}, {3, 4}};
  vector<pair<int, int>> l = {{1, 2}, {3, 4}, {5, 6}};

  vector<pair<int, int>> a;
  a.push_back({1, 2});

  // 구조체에도 사용할 수 있음.
  vector<Point> points;
  points.push_back({1, 2});
}

// 구조체에 초기값 추가
struct Point2 {
  double x = 1.0, y = 2.0;
};

// #3. tie
void tie_example() {
  pair<int, int> p = {1, 2};
  int a, b;
  tie(b, a) = p;
  cout << a << " " << b << '\n';

  // tie를 통한 swap
  a = 10;
  b = 20;
  tie(a, b) = make_pair(b, a);

  // tie에서 무시할 값이 있으면 ignore 이용
  tie(a, ignore) = make_pair(20, 30);
}

// #4. 여러 숫자 min and max
void min_max_example() {
  int a = min({1, 2, 3});
  int b = max({1, 2, 3});

  // min 과 max 동시에 구하기
  int t1, t2;
  tie(t1, t2) = minmax({1, 2, 3});
}

// #5. auto
void auto_example() {
  auto a = 0, b = 1;

  vector<int> v = {1, 2, 3, 4, 5};
  for (auto it = v.begin(); it != v.end(); it++) {
    cout << *it << '\n';
  }

  map<string, pair<int, int>> m = {{"Saerom", {24, 107}},
                                   {"Hayoung", {24, 929}}};
  for (auto it = m.begin(); it != m.end(); it++) {
    cout << (it->first) << ' ' << (it->second.first) << ' '
         << (it->second.second) << '\n';
  }
}

// #6. Range-based for
void range_based_for_example() {
  vector<int> a = {1, 2, 3, 4, 5};
  for (auto i : a) {
    printf("%d\n", i);
  }

  // &를 사용하지 않으면 값 복사가 일어나기 때문에 사용을 권장
  set<string> s = {"Saerom", "Hayoung", "Gyuri"};
  for (auto &name : s) {
    cout << name << '\n';
  }

  for (char c : "ABC") {
    // 4번 수행됨. (\0까지 포함)
  }

  for (char c : string("ABC")) {
    // 3번 수행됨.
  }
}

// #7. tuple
void tuple_example() {
  tuple<int, int, int> t(1, 2, 3);
  tuple<int, int, int> t2 = make_tuple(1, 2, 3);

  int a = get<0>(t);
  int b = get<1>(t);
  int c = get<2>(t);

  cout << a << ' ' << b << ' ' << c << '\n';

  // 아래와 같은 방식으로는 사용할 수 없음.
  for (int i = 0; i < 3; i++) {
    // int a = get<i>(t);
  }

  tie(a, b, c) = t;
}

// #8. Lambda
void lambda_example() {
  // [] : captures
  // () : parameters
  // {} : body
  auto func = []() {};

  // lambda with sort
  vector<string> v = {"Saerom", "Hayoung", "Gyuri"};
  sort(v.begin(), v.end(),
       [](const string &u, const string &v) { return u > v; });
  for (auto &name : v) {
    cout << name << '\n';
  }

  // 외부 변수가 필요한 경우, captures에 &를 붙이면 됨.
  int cmp_idx = 1;
  sort(v.begin(), v.end(), [&](const string &u, const string &v) {
    return u[cmp_idx] > v[cmp_idx];
  });
  for (auto &name : v) {
    cout << name << '\n';
  }

  // 일반 함수와 같이 사용하려면
  auto sum = [](int a, int b) { return a + b; };
  // 아래와 같음
  // function<int(int, int)> sum = [](int a, int b) { return a + b; };
  printf("%d\n", sum(1, 2));

  // lambda를 통해 재귀 호출을 하려면 auto 대신 function으로 정의
  function<int(int)> f = [&](int x) {
    if (x <= 0)
      return 1;
    else
      return x * f(x - 1);
  };
}

// #9. emplace
void emplace_example() {
  // push_back과 다르게 emplace_back는 객체가 아닌
  // 인자들을 받아 vector 내에서 객체를 생성하여 추가하므로
  // 성능 상 유리함.
  // 객체를 추가해야하는 경우 이 방식 권장
  vector<pair<int, int>> v;
  v.emplace_back(1, 2);

  vector<tuple<int, int, int>> v2;
  v2.emplace_back(3, 4, 5);
}

main() { cout << "Test" << endl; }