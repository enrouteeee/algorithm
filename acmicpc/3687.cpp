#include <vector>
#include <iostream>

using namespace std;

int num[10] = {0, 0, 1, 7, 4, 2, 6, 8, 10};

long long dp[101];

int main(){

  dp[0] = 0; dp[1] = 0; dp[2] = 1; dp[3] = 7; dp[4] = 4; dp[5] = 2; dp[6] = 6; dp[7] = 8; dp[8] = 10;
  for(int i=9; i<101; i++)
    dp[i] = __LONG_MAX__;

  int add[9] = {0, 0, 1, 7, 4, 2, 0, 8, 10};
  for(int i=9; i<101; i++){
    for(int j=2; j<=7; j++){
      dp[i] = min(dp[i], (dp[i-j]*10 + add[j]));
    }
  }


  int T; cin >> T;
  for(int t=0; t<T; t++){
    int N; cin >> N;

    cout << dp[N];

    //가장 큰 수
    int maxi;
    if(N % 2 == 0){
      maxi = 1;
      for(int i=0; i< N/2-1; i++){
        maxi = maxi*10+1;
      }
    }
    else{
      maxi = 7;
      for(int i=0; i< N/2-1; i++){
        maxi = maxi*10+1;
      }
    }

    cout << N;

  }


  return 0;
}