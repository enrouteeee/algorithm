//어두운 길
#include <iostream>
#include <queue>

using namespace std;

int parent[200001];

void uni(int a, int b){
  a = parent[a];
  b = parent[b];

  if(a < b)
    parent[b] = parent[a];
  else
    parent[a] = parent[b];
}

int findP(int a){
  if(a == parent[a])
    return a;
  
  return parent[a] = findP(parent[a]);
}

bool checkC(int a, int b){
  if(findP(a) == findP(b))
    return true;
  return false;
}


int main(){

  int N, M;
  cin >> N >> M;

  for(int i=0; i<N; i++)
    parent[i] = i;

  priority_queue<pair<int,pair<int,int>>> pq;
  int sum = 0;
  for(int i=0; i<M; i++){
    int a, b, c;
    cin >> a >> b >> c;
    pq.push(make_pair(-c,make_pair(a,b)));
    sum += c;
  }

  int ans = 0;
  while(!pq.empty()){
    int d = -pq.top().first;
    int e1 = pq.top().second.first;
    int e2 = pq.top().second.second;
    pq.pop();

    if(checkC(e1, e2))
      continue;

    uni(e1, e2);
    ans += d;
  }

  cout << sum - ans;

  return 0;
}

/*
7 11
0 1 7
0 3 5
1 2 8
1 3 9
1 4 7
2 4 5
3 4 15
3 5 6
2 5 8
4 6 9
5 6 11
*/