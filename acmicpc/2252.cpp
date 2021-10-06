#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int N, M;
int indegree[32001]; //들어오는 진입 차수
vector<int> v[32001];

int check[32001];

int main(){

  cin >> N >> M;

  for(int i=0; i<M; i++){
    int a, b; cin >> a >> b;
    indegree[b]++;
    v[a].push_back(b); // a정점에서 b정점으로 가는 간선 있다
  }

  queue<int> q;

  for(int i=1; i<=N; i++){
    if(indegree[i] == 0)
      q.push(i);
  }

  while(!q.empty()){
    int node = q.front();
    q.pop();

    cout << node << " ";

    for(int i=0; i<v[node].size(); i++){
      if(--indegree[v[node][i]] == 0){
        q.push(v[node][i]);
      }
    }
  }

  return 0;
}