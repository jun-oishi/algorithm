#include <iostream>
#include <stack>
using namespace std;

constexpr int MAX_N = 100000;
constexpr int NOT_FOUND = -1;
int S[MAX_N];

int binarySearch(int needle, int size) {
  int left = 0;
  int right = size;
  while (left < right) {
    int mid = (left + right) / 2;
    if (S[mid] == needle) {
      return mid;
    } else if (needle < S[mid]) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return NOT_FOUND;
}

int main() {
  int n, q;
  stack<int> t;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> S[i];
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
    if (binarySearch(x, n) != NOT_FOUND) {
      count++;
    }
  }
  cout << count << endl;
}