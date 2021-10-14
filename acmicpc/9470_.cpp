#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int indegree[1001]; //들어오는
vector<int> v[1001];  //나가는
int T, K, M, P;


int main(){

  cin >> T;
  for(int t=0; t<T; t++){
    cin >> K >> M >> P;
    
    for(int p=0; p<P; p++){
      int a, b;
      cin >> a >> b;
      indegree[b]++;
      v[a].push_back(b);
    }

    int order[1001] = {0,};
    vector<int> indegrees[1001];
    queue<int> q;
    for(int i=1; i<=M; i++){
      if(indegree[i] == 0){
        q.push(i);
        order[i] = 1;
      }
    }

    int max = 0;
    while(!q.empty()){
      int node = q.front();
      q.pop();

      for(int i=0; i<v[node].size(); i++){
        indegree[v[node][i]]--;
        indegrees[v[node][i]].push_back(order[node]);
        if(indegree[v[node][i]] == 0){
          q.push(v[node][i]);
          sort(indegrees[v[node][i]].begin(), indegrees[v[node][i]].end(), greater<>());
          if(indegrees[v[node][i]][0] == indegrees[v[node][i]][1]){
            order[v[node][i]] = indegrees[v[node][i]][0]+1;
          }
          else{
            order[v[node][i]] = indegrees[v[node][i]][0];
          }
          if(max < order[v[node][i]])
            max = order[v[node][i]];
        }
      }
    }

    cout << K << " " << max << '\n';
  }

  return 0;
}