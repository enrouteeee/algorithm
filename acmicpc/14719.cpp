#include <stdio.h>
#include <iostream>

using namespace std;

int board[500][500];

int main(){

  int H, W;
  cin >> H >> W;

  for(int i=0; i<W; i++){
    int a;
    cin >> a;
    for(int j=0; j<a; j++){
      board[j][i] = 1;
    }
  }

  int ans = 0;

  for(int i=0; i<H; i++){
    int tmp = 0;
    int flag = 0;
    for(int j=0; j<W; j++){
      if(board[i][j] == 1){
        if(flag == 0){
          flag = 1;
          tmp = 0;
        }
        else if(flag == 1){
          ans += tmp;
          tmp = 0;
        }
      }
      else if(board[i][j] == 0){
        tmp++;
      }
    }
  }

  cout << ans;

  return 0;
}