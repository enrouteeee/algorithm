//특정 거리의 도시 찾기
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


vector<int> graph[300000];
int visit[300000];

int main(){

  vector<int> ans;

  int N, M, K, X;

  cin >> N >> M >> K >> X;

  for(int i=0; i<M; i++){
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
  }
  
  //번호, 현재거리
  queue<pair<int,int>> q;
  q.push(make_pair(X, 0));

  while(!q.empty()){
    pair<int,int> tmp_p = q.front();
    q.pop();

    if(visit[tmp_p.first])
      continue;
    visit[tmp_p.first] = 1;

    if(tmp_p.second == K){
      ans.push_back(tmp_p.first);
    }
    else if(tmp_p.second > K)
      break;

    for(int i=0; i<graph[tmp_p.first].size(); i++){
      if(visit[graph[tmp_p.first][i]]){
        continue;
      }
      q.push(make_pair(graph[tmp_p.first][i], tmp_p.second+1));
    }
  }

  if(ans.empty()){
    cout << -1;
    return 0;
  }

  sort(ans.begin(), ans.end());
  for(int i=0; i<ans.size(); i++){
    cout << ans[i] << endl;
  }

  return 0;
}