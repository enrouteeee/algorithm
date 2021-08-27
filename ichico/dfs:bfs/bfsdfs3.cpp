//경쟁적 전염
#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

struct cmp {
  bool operator()(tuple<int,int,int,int> t1, tuple<int,int,int,int> t2){
    if(get<3>(t1) == get<3>(t2))
      return get<2>(t1) > get<2>(t2);
    return get<3>(t1) > get<3>(t2);
  }
};

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main(){

  int N, K;
  cin >> N >> K;

  int board[200][200];
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      cin >> board[i][j];
    }
  }

  int S, X, Y;
  cin >> S >> X >> Y;

  priority_queue<tuple<int,int,int,int>, vector<tuple<int,int,int,int>>, cmp> pq;
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(board[i][j] != 0)
        pq.push(make_tuple(i,j,board[i][j],0));
    }
  }

  while(!pq.empty()){
    tuple<int,int,int,int> t_tmp = pq.top();
    pq.pop();

    int x = get<0>(t_tmp);
    int y = get<1>(t_tmp);
    int v = get<2>(t_tmp);
    int t = get<3>(t_tmp);

    if(t == S)
      break;

    for(int d=0; d<4; d++){
      int nx = x + dx[d];
      int ny = y + dy[d];

      if(nx < 0 || nx >= N || ny <0 || ny >= N)
        continue;

      if(board[nx][ny] != 0)
        continue;
      
      board[nx][ny] = v;
      pq.push(make_tuple(nx,ny,v,t+1));
    }
  }

  cout << board[X-1][Y-1] << endl;

  return 0;
}