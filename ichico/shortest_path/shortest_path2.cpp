//정확한 순위
#include<iostream>

using namespace std;

int main(){

  int N, M;
  cin >> N >> M;

  int graph[501][501] = {0,};
  for(int i=0; i<M; i++){
    int a, b;
    cin >> a >> b;
    graph[a-1][b-1] = 1;
    graph[b-1][a-1] = -1;
  }

  for(int k=0; k<N; k++){
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        if(graph[i][k] == graph[k][j]){
          if(graph[i][k] == 1){
            graph[i][j] = 1;
            graph[j][i] = -1;
          }
          else if(graph[i][k] == -1){
            graph[i][j] = -1;
            graph[j][i] = 1;
          }
        }
      }
    }
  }

  int ans = 0;
  for(int i=0; i<N; i++){
    int flag = 1;
    for(int j=0; j<N; j++){
      if(i == j) continue;

      if(graph[i][j] == 0){
        flag = 0;
        break;
      }
    }
    if(flag == 1)
      ans++;
  }

  cout << ans << '\n';

  return 0;
}