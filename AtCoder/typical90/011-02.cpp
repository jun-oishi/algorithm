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

// Tの仕事のうちi%(2^k)=1なるk番目の仕事すべてをこなせればその場合の報酬を
// こなせなければ0を返す
ll can_process(ll i) {
  ll now = 0;
  ll score = 0;
  for (ll j=0; j<N; j++) {
    if ((i & (1<<j)) == 0) continue;
    if (now+T[j].C > T[j].D) return 0;
    now += T[j].C;
    score += T[j].S;
    continue;
  }
  return score;
}

int main() {
  cin >> N;
  T.resize(N);
  for (int i=0; i<N; i++) {
    cin >> T[i].D >> T[i].C >> T[i].S;
  }

  sort(T.begin(), T.end());

  ll max_score = 0;
  for (ll i=0; i<(1l<<N); i++) {
    max_score = max(max_score, can_process(i));
  }

  cout << max_score << endl;

  return 0;
}