#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int T, N, K;

int main(){

  cin >> T;

  for(int t=0; t<T; t++){
    cin >> N >> K;
    int cost[1001];
    for(int i=1; i<=N; i++){
      int a; cin >> a;
      cost[i] = a;
    }

    int indegree[1001] = {0,};
    vector<int> edge[1001];

    for(int i=0; i<K; i++){
      int a, b; cin >> a >> b;
      edge[a].push_back(b);
      indegree[b]++;
    }

    int end; cin >> end;

    long long answer = cost[end];
    vector<int> times[1001];

    // node,time
    queue<pair<int,int>> q;
    for(int i=1; i<=N; i++){
      if(indegree[i] == 0){
        q.push({i,cost[i]});
      }
    }

    int flag = 0;
    while(!q.empty()){
      int node = q.front().first;
      int time = q.front().second;
      q.pop();

      for(int i=0; i<edge[node].size(); i++){
        int now = edge[node][i];
        times[now].push_back(time);

        if(--indegree[now] == 0){
          if(now == end)
            flag = 1;

          int max = 0;
          for(int j=0; j<times[now].size(); j++)
            if(max < times[now][j]) max = times[now][j];
          
          q.push({now, max+cost[now]});

          if(now == end){
            flag = 1;
            answer= max + cost[now];
            break;
          }
        }
      }
      if(flag)
        break;
    }

    cout << answer << '\n';
  }


  return 0;
}