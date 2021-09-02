//화성탐사
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

#define INF 1e9;

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main(){

  int T;
  cin >> T;

  vector<int> ans;
  for(int t=0; t<T; t++){
    int N;
    cin >> N;
    int board[125][125];
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        cin >> board[i][j];
      }
    }

    int d[125][125];
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        d[i][j] = INF;
      }
    }
    queue<tuple<int,int,int>> q;
    d[0][0] = board[0][0];
    q.push(make_tuple(0,0,board[0][0]));

    while(!q.empty()){
      tuple<int,int,int> t_tmp = q.front();
      q.pop();
      int x = get<0>(t_tmp);
      int y = get<1>(t_tmp);
      int l = get<2>(t_tmp);

      if(d[x][y] < l)
        continue;

      d[x][y] = l;

      for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= N || ny < 0 || ny >= N)
          continue;

        if(d[nx][ny] > l + board[nx][ny])
          q.push(make_tuple(nx,ny,l + board[nx][ny]));
      }
    }
    ans.push_back(d[N-1][N-1]);
  }
  
  for(int t=0; t<T; t++)
    cout << ans[t] << '\n';

  return 0;
}

/*
3
3
5 5 4
3 9 1
3 2 7
5
3 7 2 0 1
2 8 0 9 1
1 2 1 8 1
9 8 9 2 0
3 6 5 1 5
7
9 0 5 1 1 5 3
4 1 2 1 6 5 3
0 7 6 1 6 8 5
1 1 7 8 3 2 3
9 4 0 7 6 4 1
5 8 3 2 4 8 3
7 4 8 4 8 3 4

20
19
36
*/