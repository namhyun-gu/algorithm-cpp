#include <bits/stdc++.h>
using namespace std;

// Reference : http://codeforces.com/blog/entry/15643

// #2. Name of argument in macros
#define what_is(x) cerr << #x << " is " << x << endl;

// #4. Hidden function
void hidden_function_example() { int gcd = __gcd(18, 27); }

// move vector
void move_vector_example() {
  vector<int> v = {1, 2, 3, 4};
  vector<int> w = move(v);

  cout << "v: ";
  for (auto i : v) cout << i << ' ';

  cout << "\nw: ";
  for (auto i : w) cout << i << ' ';

  // v:
  // w: 1 2 3 4
}

// #7. C++0x Strings
// 1) Raw Strings
void raw_strings_example() {
  string s = R"(Hello, World!)";  // Stored: "Hello, World!"

  // Raw String은 escape 문자 \n 혹은 \"를 무시한다.
  string str = "Hello\tWorld\n";
  string r_str = R"(Hello\tWorld\n)";
  cout << str << r_str;

  // Hello	World
  // Hello\tWorld\n

  // 여러 줄로 사용할 경우 \n이 자동으로 포함된다.

  string r_str =
      R"(Dear Programmers,
    I'm using C++11
    Regards, Swift!)";
  cout << r_str;

  // Dear Programmer,
  // I'm using C++11
  // Regards, Swift!
}

// 3) User-defined literals
long long operator""_m(unsigned long long literal) { return literal; }

long double operator""_cm(unsigned long long literal) {
  return literal / 100.0;
}

long long operator""_km(unsigned long long literal) { return literal * 1000; }

// 아래의 형식을 가져야하며,
// [returnType] operator "" _[name]([parameters]) { [body] }

// 아래의 타입의 인수만 사용할 수 있다.
// (const char *)
// (unsigned long long int)
// (long double)
// (char)
// (wchar_t)
// (char16_t)
// (char32_t)
// (const char *, size_t)
// (const wchar_t *, size_t)
// (const char16_t *, size_t)
// (const char32_t *, size_t)

void user_defined_literal_example() {
  cout << 250_m << " meters \n";
  cout << 12_km << " meters \n";
  cout << 421_cm << " meters \n";
}