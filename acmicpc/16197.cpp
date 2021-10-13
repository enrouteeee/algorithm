#include <vector>
#include <iostream>
#include <stdio.h>

using namespace std;

int N, M;
int board[21][21];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int flag = 0;
int answer = 11;
void dfs(int h, int c1x, int c1y, int c2x, int c2y, int check){
    
  if(h >= answer){
      return;
  }
  
  if(check){
    flag = 1;
    answer = h;
    return;
  }
  

  for(int i=0; i<4; i++){
    int n1x = c1x + dx[i];
    int n1y = c1y + dy[i];
    int n2x = c2x + dx[i];
    int n2y = c2y + dy[i];

    int cnt = 0;
    if(n1x < 0 || n1y < 0 || n1x >= N || n1y >=M){
      cnt++;
    }
    else{
      if(board[n1x][n1y] == 1){
        n1x = c1x;
        n1y = c1y;
      }
    }
    if(n2x < 0 || n2y < 0 || n2x >= N || n2y >=M){
      cnt++;
    }
    else{
      if(board[n2x][n2y] == 1){
        n2x = c2x;
        n2y = c2y;
      }
    }
    
    //printf("%d : (%d,%d) (%d,%d) \n", cnt, n1x, n1y, n2x, n2y);

    if(cnt == 1){
      dfs(h+1, n1x, n1y, n2x, n2y, 1);
    }
    else if(cnt == 0){
      dfs(h+1, n1x, n1y, n2x, n2y, 0);
    }
  }
}

int main(){

  cin >> N >> M;
  
  int cnt = 0;

  int c1x, c1y;
  int c2x, c2y;

  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      char c; cin >> c;
      if(c == 'o'){
        if(cnt == 1){
          c2x= i;
          c2y = j;
        }
        else{
          c1x = i;
          c1y = j;
          cnt++;
        }
      }
      else if(c == '.'){
        board[i][j] = 0;
      }
      else if(c == '#'){
        board[i][j] = 1;
      }
    }
  }

  dfs(0, c1x, c1y, c2x, c2y, 0);

  if(flag)
    cout << answer;
  else
    cout << -1;

  return 0;
}