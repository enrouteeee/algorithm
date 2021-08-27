//연구소
#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int N, M;
int board[8][8];
int ans;

queue<pair<int,int>> q_;

int nBoard[8][8];
void sol(int i_, int j_, int h){
  if(h == 3){
    int nBoard[8][8];
    for(int i=0; i<N; i++){
      for(int j=0; j<M; j++){
        nBoard[i][j] = board[i][j];
      }
    }

    queue<pair<int,int>> q = q_;
    
    while(!q.empty()){
      pair<int,int> p = q.front();
      q.pop();

      for(int d=0; d<4; d++){
        int nx = p.first + dx[d];
        int ny = p.second + dy[d];

        if(nx < 0 || nx >= N || ny < 0 || ny >= M)
          continue;
        
        if(nBoard[nx][ny] != 0)
          continue;

        nBoard[nx][ny] = 2;
        q.push(make_pair(nx,ny));
      }
    }

    int cnt = 0;
    for(int i=0; i<N; i++){
      for(int j=0; j<M; j++){
        if(nBoard[i][j] == 0)
          cnt++;
      }
    }
    
    if(ans < cnt)
      ans = cnt;
    
    return;
  }

  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      if(i < i_)
        continue;
      else if(i == i_ && j <= j_)
        continue;

      if(board[i][j] != 0)
        continue;

      board[i][j] = 1;
      setwall(i,j,h+1);
      board[i][j] = 0;
    }
  }
}

int main(){

  cin >> N >> M;

  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      cin >> board[i][j];
      if(board[i][j] == 2)
        q_.push(make_pair(i,j));
    }
  }

  sol(-1,-1,0);

  cout << ans;

  return 0;
}
