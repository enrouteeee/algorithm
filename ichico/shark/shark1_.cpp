//아기 상어
#include <stdio.h>
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

typedef struct shart{
  int x;
  int y;
  int s;
  int f;
}shark;

int N;
int board[21][21];
shark bs;

//위 왼 아 오
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

int simul(){
  int visit[21][21]={0,};
  
  queue<tuple<int,int,int>> q;
  q.push(make_tuple(bs.x, bs.y, 0));

  while(!q.empty()){
    int x = get<0>(q.front());
    int y = get<1>(q.front());
    int d = get<2>(q.front());

    if(visit[x][y])
      continue;
    
    
  }
}

int main(){

  cin >> N;
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      cin >> a;
      if(a == 9){
        bs.x = i;
        bs.y = j;
        bs.s = 2;
        bs.f = 0;
        continue;
      }
      board[i][j] = a;
    }
  }

  int ans = 0;
  int d;
  while(1){
    if(d = simul() == 0)
      break;
    ans += d;
  }

  cout << ans << '\n';


  return 0;
}