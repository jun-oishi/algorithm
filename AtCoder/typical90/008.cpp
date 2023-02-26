#include<iostream>
using namespace std;

const int mod = 1000000007;

int main() {
  int N;
  cin >> N;
  char S[N];
  for (int i=0; i<N; i++) cin >> S[i];

  // dp[i][j] : Sのi文字目を含まず左から`atcoder`のj文字目までを選ぶ場合の数
  char atcoder[7] = {'a','t','c','o','d','e','r'};
  int l=7;
  long long dp[N+1][l+1];
  dp[0][0] = 1;
  for (int i=1; i<=l; i++) dp[0][i] = 0;
  for (int i=0; i<N; i++) {
    dp[i][0] = 1;
    for (int j=0; j<l; j++) {
      dp[i+1][j+1] = dp[i][j+1];
      if (S[i] == atcoder[j]) dp[i+1][j+1] += dp[i][j];
      dp[i+1][j+1] %= mod;
    }
  }

  cout << dp[N][l] << endl;

  return 0;
}