  //인구 이동
  #include <iostream>
  #include <vector>
  #include <queue>
  #include <stdlib.h>

  using namespace std;

  int N, L, R;
  int board[51][51];

  int dx[4] = {0, 0, 1, -1};
  int dy[4] = {1, -1, 0, 0};

  int main(){

    cin >> N >> L >> R;

    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        cin >> board[i][j];
      }
    }

    int ans = 0;
    while(1){
      int flag = 0;
      int visit[51][51] = {0,};
      int cnt = 1;
      for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
          if(visit[i][j] != 0)
            continue;

          queue<pair<int,int>> q;
          q.push(make_pair(i,j));

          while(!q.empty()){
            pair<int,int> tmp_p = q.front();
            q.pop();

            int x = tmp_p.first;
            int y = tmp_p.second;
            if(visit[x][y])
              continue;

            visit[x][y] = cnt;
            for(int d=0; d<4; d++){
              int nx = x + dx[d];
              int ny = y + dy[d];
              if(nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;

              int sub = abs(board[nx][ny] - board[x][y]);
              if(visit[nx][ny] || sub < L || sub > R)
                continue;

              q.push(make_pair(nx, ny));
              flag = 1;
            }
          }
          cnt++;
        }
      }

      int sum[3000][2] = {0,};
      for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
          sum[visit[i][j]][0] += board[i][j];
          sum[visit[i][j]][1]++;
        }
      }

      for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
          board[i][j] = sum[visit[i][j]][0] / sum[visit[i][j]][1];
        }
      }

      if(!flag)
        break;

      ans++;
    }

    cout << ans;

    return 0;
  }