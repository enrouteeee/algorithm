#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int N, M, V;
int board[1001][1001];
int visit[1001];

void dfs(int v){
  visit[v] = 1;
  cout << v << " ";

  for(int i=1; i<=N; i++){
    if(i == v || visit[i] || board[v][i] == 0)
      continue;

    dfs(i);
  }
}

void bfs(int v){
  queue<int> q;
  q.push(v);

  while(!q.empty()){
    int node = q.front();
    q.pop();

    if(visit[node])
      continue;
    
    visit[node] = 1;
    cout << node << " ";
    for(int i=1; i<=N; i++){
      if(i==node || visit[i] || board[node][i] == 0)
        continue;
      
      q.push(i);
    }
  }
}

int main(){

  cin >> N >> M >> V;
  for(int i=0; i<M; i++){
    int a, b;
    cin >> a >> b;
    board[a][b] = 1;
    board[b][a] = 1;
  }

  dfs(V);
  cout << '\n';

  for(int i=1; i<=N; i++)
    visit[i] = 0;
  bfs(V);

  return 0;
}