#include <bits/stdc++.h>
using namespace std;

void show(stack<int> s) {
  while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }
  cout << endl;
}

int calc(queue<char> input) {
  stack<int> s;
  while (!input.empty()) {
    char c = input.front();
    input.pop();
    if (c == '+') {
      int a = s.top(); s.pop();
      int b = s.top(); s.pop();
      s.push(a + b);
    } else if (c == '-') {
      int a = s.top(); s.pop();
      int b = s.top(); s.pop();
      s.push(b - a);
    } else if (c == '*') {
      int a = s.top(); s.pop();
      int b = s.top(); s.pop();
      s.push(a * b);
    } else {
      s.push(c - '0');
    }
  }
  return s.top();
}

int main() {
  string str;
  getline(cin, str);
  queue<char> q;
  for (char c : str) {
    if (c != ' ') q.push(c);
  }
  int result = calc(q);
  cout << result << endl;
}
