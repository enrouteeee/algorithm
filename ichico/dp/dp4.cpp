#include <iostream>
#include <vector>
//병사 배치하기
#include <algorithm>

using namespace std;

int main(){

  int N;
  cin >> N;

  vector<int> sold;
  for(int i=0; i<N; i++){
    int a;
    cin >> a;
    sold.push_back(a);
  }

  reverse(sold.begin(), sold.end());

  int dp[2001];
  for(int i=0; i<N; i++)
    dp[i] = 1;

  for(int i=1; i<N; i++){
    for(int j=0; j<i; j++){
      if(sold[j] < sold[i]){
        dp[i] = max(dp[j]+1, dp[i]);
      }
    }
  }

  int ans = 0;
  for(int i=0; i<N; i++){
    ans = max(ans, dp[i]);
  }

  cout << N-ans << '\n';

  return 0;
}