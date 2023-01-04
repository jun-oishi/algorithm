#include <iostream>
#include <set>
#include <stack>
using namespace std;

int main() {
  int n, q;
  set<int> s;
  stack<int> t;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    s.insert(x);
  }
  cin >> q;
  for (int i = 0; i < q; i++) {
    int x;
    cin >> x;
    t.push(x);
  }
  int count = 0;
  while (!t.empty()) {
    int x = t.top();
    t.pop();
    if (s.find(x) != s.end()) {
      count++;
    }
  }
  cout << count << endl;
}