#include <vector>
#include <iostream>
#include <queue>

#define INF 987654321

using namespace std;

int N, M;
int s, e;
vector<pair<int,int>> graph[1001];

int d[1001];

void dijkstra(int s){
  //dist, node
  priority_queue<pair<int,int>> pq;

  pq.push(make_pair(0, s));
  d[s] = 0;

  while(!pq.empty()){
    int dist = -pq.top().first;
    int now = pq.top().second;
    pq.pop();

    if(d[now] < dist)
      continue;

    for(int i=0; i<graph[now].size(); i++){
      int cost = dist + graph[now][i].second;
      
      if(cost < d[graph[now][i].first]){
        d[graph[now][i].first] = cost;
        pq.push(make_pair(-cost, graph[now][i].first));
      }
    }
  }
}

int main(){

  cin >> N >> M;
  for(int i=0; i<M; i++){
    int a, b, c;
    cin >> a >> b >> c;
    graph[a].push_back(make_pair(b,c)); // a 에서 b로 갖는 비용 c
  }
  cin >> s >> e;

  for(int i=0; i<=N; i++){
    d[i] = INF;
  }

  dijkstra(s);

  cout << d[e];

  return 0;
}