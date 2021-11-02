#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int board[101][101];
int visit[101][101];

int main(){

  int N, M;
  cin >> N >> M;

  int power1 = 0;
  int power2 = 0;

  for(int i=0; i<M; i++){
    for(int j=0; j<N; j++){
      char c; cin >> c;
      if(c == 'W'){
        board[i][j] = 1;
      }
      else if(c == 'B'){
        board[i][j] = 2;
      }
    }
  }

  int dx[4] = {0, 0, 1, -1};
  int dy[4] = {1, -1, 0, 0};

  queue<pair<int,pair<int,int>>> q;
  for(int i=0; i<M; i++){
    for(int j=0; j<N; j++){
      if(visit[i][j])
        continue;
      
      q.push({board[i][j],{i,j}});

      int cnt = 0;
      while(!q.empty()){
        int color = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        if(visit[x][y])
          continue;
        
        visit[x][y] = 1;
        cnt++;
        for(int d=0; d<4; d++){
          int nx = x+dx[d];
          int ny = y+dy[d];

          if(nx < 0 || ny < 0 || nx >= M || ny >= N)
            continue;
          
          if(visit[nx][ny] || board[nx][ny] != color)
            continue;
          
          q.push({board[nx][ny],{nx,ny}});
        }
      }

      if(board[i][j] == 1){
        power1 += cnt*cnt;
      }
      else if(board[i][j] == 2){
        power2 += cnt*cnt;
      }
    }
  }
  
  cout << power1 << " " << power2;

  return 0;
}