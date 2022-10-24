#include <bits/stdc++.h>
using namespace std;

void show(deque<int> dq) {
  while (!dq.empty()) {
    cout << dq.front() << " ";
    dq.pop_front();
  }
  cout << endl;
}

void pop_back_twice_ignoring_zero(deque<int> &dq) {
  cout << "exchanging";
  for (int i = 0; i < 2; i++) {
    if (dq.back() == 0) {
      dq.pop_back();
      cout << " " << dq.back();
      dq.pop_back();
      dq.push_back(0);
    } else {
      cout << " " << dq.back();
      dq.pop_back();
    }
  }
  cout << endl;
}

int main() {
  int n;
  cin >> n;
  deque<int> a;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a.push_back(x);
  }

  sort(a.begin(), a.end());
  a.push_back(0); // ダブりとのセパレータ
  int head = 0; // 読み終わった巻
  while (!a.empty()) {
    cout << "head: " << head << " ";
    if (a.front() <= head && a.front() != 0) {
      a.push_back(a.front());
      a.pop_front();
      continue;
    }
    if (a.front() == head+1) { // 次巻を持っている場合
      // 次に進む
      a.pop_front();
      head++;
      continue;
    } else if (a.size() >= 3) { // 交換が可能な場合("0"は除いて数える)
      // 末尾2冊を売ってheadをすすめる
      pop_back_twice_ignoring_zero(a);
      head++;
      continue;
    }
    break;
  }

  cout << head << endl;
}