// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <deque>
#include <stack>
using namespace std;

using pool = pair<int,int>; // 左端位置,面積

void showPool(deque<pool> pools) {
  cout << "{";
  for (auto p :pools) {
    cout << "(" << p.first << ", " << p.second << "), ";
  }
  cout << "}" << endl;
}

void showDecline(stack<int> decline) {
  cout << "{";
  while (!decline.empty()) {
    cout << decline.top() << ", ";
    decline.pop();
  }
  cout << "}" << endl;
}

int main() {
  string terr;
  cin >> terr;
  int x_now = 0;
  int total = 0;
  stack<int> decline;
  deque<pool> pools;
  for (char c: terr) {
    // cout << "x_now: " << x_now << ", c:" << c << endl;
    // showDecline(decline);
    if (c == '\\') {
      decline.push(x_now);
    } else if (c == '/') {
      if (!decline.empty()) {
        int left = decline.top();
        decline.pop();
        int area = x_now - left;
        while (!pools.empty() && pools.back().first > left) {
          area += pools.back().second;
          total -= pools.back().second;
          pools.pop_back();
        }
        pools.push_back(pool(left, area));
        total += area;
      }
    }
    // cout << "-> ";
    // showPool(pools);
    x_now++;
  }

  cout << total << endl;
  if (pools.empty()) {
    cout << pools.size() << endl;
    return 0;
  } else {
    cout << pools.size() << " ";
    while (true) {
      cout << pools.front().second;
      pools.pop_front();
      if (pools.empty()) break;
      cout << " ";
    }
    cout << endl;
  }
}
