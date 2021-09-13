//치킨 배달 https://www.acmicpc.net/problem/15686
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

int N;
int C;
int M;
vector<pair<int,int>> chick;
vector<pair<int,int>> house;
int selected[14];

int ans = 987654321;
void dfs(int n, int i_){
  if(n <= M && n > 0){
    int sum = 0;
    for(int i=0; i<house.size(); i++){
      int mini = 987654321;
      for(int j=0; j<C; j++){
        if(selected[j] == 0)
          continue;
        
        int tmp = abs(house[i].first - chick[j].first) + abs(house[i].second - chick[j].second);
        if(tmp < mini)
          mini = tmp;
      }
      sum += mini;
    }
    if(ans > sum){
      ans = sum;
    }
  }

  if(n > M)
    return;

  for(int i=i_; i<C; i++){
    selected[i] = 1;
    dfs(n+1, i+1);
    selected[i] = 0;
  }

}

int main(){

  cin >> N >> M;
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      int a;
      cin >> a;
      if(a == 1){
        house.push_back(make_pair(i, j));
      }
      else if(a == 2){
        chick.push_back(make_pair(i,j));
        C++;
      }
    }
  }

  dfs(0, 0);

  cout << ans;


  return 0;
}
