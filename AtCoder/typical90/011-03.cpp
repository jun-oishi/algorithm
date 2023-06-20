#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

struct Task {
  ll D=0, C=0, S=0;
  bool operator<(const Task &right) const {
    return this->D < right.D;
  }
};

ll max(ll a, ll b) {return a > b ? a : b;};

int N;
vector<Task> T;

int main() {
  cin >> N;
  T.resize(N);
  for (int i=0; i<N; i++) {
    cin >> T[i].D >> T[i].C >> T[i].S;
  }

  sort(T.begin(), T.end());

  int max_D = (*T.rbegin()).D;
  cout << "max_D:" << max_D << endl;
  // d[i][j]:i+1番目以降の仕事を一切しない場合にj日目までの間に稼げる最大報酬
  ll dp[N+1][max_D+1];

  for (int j=0; j<=max_D; j++) dp[0][j] = 0;
  for (int i=1; i<=N; i++) {
    for (int j=0; j<max_D; j++) {
      if (T[i].C <= j && j <= T[i].D) { // i番目の仕事ができる場合
        dp[i][j] = max(dp[i-1][j-T[i].C]+T[i].S, dp[i-1][j]);
      } else {
        dp[i][j] = dp[i-1][j];
      }
    }
  }

  cout << dp[N][max_D] << endl;

  return 0;
}