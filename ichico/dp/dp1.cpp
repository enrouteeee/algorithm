#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int max(int a, int b, int c){
  if(a < b)
    a = b;
  return (a > c) ? a : c;
}

int main(){

  int T;
  int n, m;

  int board[21][21];
  
  cin >> T;
  for(int t=0; t<T; t++){
    cin >> n >> m;
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        cin >> board[i][j];
      }
    }

    int dp[21][21] = {0,};
    for(int i=0; i<n; i++){
      dp[i][0] = board[i][0];
    }

    for(int i=1; i<m; i++){
      for(int j=0; j<n; j++){
        if(j == 0){
          dp[j][i] = (dp[j][i-1] < dp[j+1][i-1]) ? dp[j+1][i-1] : dp[j][i-1];
          dp[j][i] += board[j][i];
        }
        else if(j == n-1){
          dp[j][i] = (dp[j][i-1] < dp[j-1][i-1]) ? dp[j-1][i-1] : dp[j][i-1];
          dp[j][i] += board[j][i];
        }
        else{
          dp[j][i] = max(dp[j-1][i-1], dp[j][i-1], dp[j+1][i-1]) + board[j][i];
        }
      }
    }

    int ans = 0;
    for(int i=0; i<n; i++){
      if(ans < dp[i][m-1])
        ans = dp[i][m-1];
    }
    cout << ans << '\n';
  }


  return 0;
}