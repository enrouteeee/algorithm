//여행계획
#include <iostream>

using namespace std;

int parent[501];

int findParent(int a){
  if(a == parent[a])
    return a;
  else
    return parent[a] = findParent(parent[a]);
}

void uni(int a, int b){
  a = findParent(a);
  b = findParent(b);
  if(a < b){
    parent[b] = parent[a];
  }
  else{
    parent[a] = parent[b];
  }
}

int main(){

  int N, M;
  cin >> N >> M;

  int path[501];

  for(int i=0; i<N; i++)
    parent[i] = i;

  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      int a;
      cin >> a;
      if(a){
        uni(i, j);
      }
    }
  }

  for(int i=0; i<M; i++){
    cin >> path[i];
  }

  int flag = 0;
  for(int i=1; i<M; i++){
    if(findParent(path[0]) != findParent(path[i]))
      flag = 1;
  }

  if(flag)
    cout << "NO";
  else
    cout << "YES";

  return 0;
}

/*
5 4
0 1 0 1 1
1 0 1 1 0
0 1 0 0 0 
1 1 0 0 0
1 0 0 0 0
2 3 4 3
*/