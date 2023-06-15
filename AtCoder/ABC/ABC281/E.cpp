#include <bits/stdc++.h>
#include <numeric>
using namespace std;

// O(M)
int pop(vector<int> &v, int n) {
  for (int i = 0; i < v.size(); i++) {
    if (v[i] == n) {
      v.erase(v.begin() + i);
      return i;
    }
  }
  return -1;
}

// O(M)
int insert(vector<int> &v, int n) {
  for (int i = 0; i < v.size(); i++) {
    if (v[i] > n) {
      v.insert(v.begin() + i, n);
      return i;
    }
  }
  v.push_back(n);
  return v.size() - 1;
}

void show(vector<int> &v) {
  cout << endl;
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  vector<int> tmp;
  for (int i = 0; i < m; i++) {
    tmp.push_back(a[i]);
  }
  sort(tmp.begin(), tmp.end());
  long long sum = accumulate(tmp.begin(), tmp.begin()+k, 0LL);
  cout << sum;
  for (int i = 1; i <= n - m; i++) {
    int popped = pop(tmp, a[i - 1]);
    int inserted = insert(tmp, a[i + m - 1]);
    // cout << endl << a[i-1] << " popped from " << popped;
    // cout << endl << a[i+m-1] << " inserted into " << inserted;
    // show(tmp);
    if (popped < k) {
      sum -= a[i-1];
      if (inserted < k) {
        sum += a[i+m-1];
      } else {
        sum += tmp[k-1];
      }
    } else if (inserted < k) {
      sum += a[i+m-1] - tmp[k];
    }
    cout << " " << sum;
  }
  cout << endl;
}