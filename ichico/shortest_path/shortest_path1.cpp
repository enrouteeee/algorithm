//플로이드
#include <iostream>

#define INF 1e9

using namespace std;

int main(){

  int N;
  int graph[101][101];

  cin >> N;
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(i == j)
        graph[i][j] = 0;
      else
        graph[i][j] = INF;
    }
  }

  int e;
  cin >> e;
  for(int i=0; i<e; i++){
    int x, y, d;
    cin >> x >> y >> d;
    if (c < graph[x-1][y-1]) graph[x-1][y-1] = d;
  }

  for(int k=0; k<N; k++){
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
      }
    }
  }

  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(graph[i][j] == INF){
        cout << 0 <<  " ";
      }
      else
        cout << graph[i][j] <<  " ";
    }
    cout << '\n';
  }


  return 0;
}