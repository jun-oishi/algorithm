#include <bits/stdc++.h>
using namespace std;
using task = pair<string, int>;

void run_simulate(queue<task> tasks, int quantum) {
  int time = 0;
  while (!tasks.empty()) {
    task t = tasks.front();
    tasks.pop();
    if (t.second <= quantum) {
      time += t.second;
      cout << t.first << " " << time << endl;
    } else {
      time += quantum;
      t.second -= quantum;
      tasks.push(t);
    }
  }
}

int main() {
  int n, q;
  cin >> n >> q;
  queue<task> tasks;
  for (int i = 0; i < n; i++) {
    string name;
    int time;
    cin >> name >> time;
    tasks.push(make_pair(name, time));
  }
  run_simulate(tasks, q);
}
