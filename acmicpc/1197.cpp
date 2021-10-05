#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int N, E;

int parent[10001];

int findParent(int a){
  if(a == parent[a])
    return a;

  return parent[a] = findParent(parent[a]);
}

void uni(int a, int b){
  a = parent[a];
  b = parent[b];

  if(a < b)
    parent[b] = parent[a];
  else
    parent[a] = parent[b];
}

int main(){

  cin >> N >> E;

  for(int i=0; i<N; i++){
    parent[i] = i;
  }

  priority_queue<pair<int, pair<int,int>>> pq;
  for(int i=0; i<E; i++){
    int a, b, c;
    cin >> a >> b >> c;
    pq.push(make_pair(-c, make_pair(a,b)));
  }

  int ans = 0;
  int cnt = 0;
  while(!pq.empty()){
    int dist = -pq.top().first;
    int node1 = pq.top().second.first;
    int node2 = pq.top().second.second;
    pq.pop();

    if(findParent(node1) == findParent(node2))
      continue;
    
    uni(node1, node2);
    ans += dist;
    cnt++;
    if(cnt == N-1)
      break;
  }

  cout << ans;

  return 0;
}