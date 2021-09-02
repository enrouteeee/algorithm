//숨바꼭질
#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

vector<pair<int,int>> graph[20001];

int d[20001];

void dijkstra(int start){
  priority_queue<pair<int,int>> pq;
  pq.push(make_pair(0, start));
  d[start] = 0;

  while(!pq.empty()){
    int dist = -pq.top().first;
    int e = pq.top().second;
    pq.pop();

    if(d[e] < dist) continue;

    for(int i=0; i<graph[e].size(); i++){
      int cost = dist + graph[e][i].second;

      if(cost < d[graph[e][i].first]){
        d[graph[e][i].first] = cost;
        pq.push(make_pair(-cost, graph[e][i].first));
      }
    }
  }
}

int main(){

  int N, M;
  cin >> N >> M;

  for(int i=0; i>M; i++){
    int a, b;
    cin >> a >> b;
    graph[a].push_back(make_pair(b, 1));
  }

  for(int i=1; i<=N; i++)
    d[i] = INF;

  dijkstra(1);

  int maxi=0;
  int maxv=0;
  for(int i=2; i<=N; i++){
    if(maxv < d[i]){
      maxi = i;
      maxv = d[i];
    }
  }
  int cnt = 0;
  for(int i=2; i<=N; i++){
    if(d[i] == maxv)
      cnt++;
  }

  cout << maxi << maxv << cnt;

  return 0;
}