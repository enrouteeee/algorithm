#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int oper[4];
int visit[4];
int num[100];

vector<int> ans;

int N;

void dfs(int tmp, int h){
  if(h == N){
    ans.push_back(tmp);
    return;
  }
  
  for(int i=0; i<4; i++){
    if(visit[i] >= oper[i])
      continue;
    
    visit[i]++;
    int tmp_ = tmp;
    if(i == 0){
      tmp = tmp + num[h];
    }
    else if(i == 1){
      tmp = tmp - num[h];
    }
    else if(i == 2){
      tmp = tmp * num[h];
    }
    else if(i == 3){
      tmp = tmp / num[h];
    }
    dfs(tmp, h+1, i);
    visit[i]--;
    tmp = tmp_;
  }
}

int main(){

  cin >> N;
  for(int i=0; i<N; i++){
    cin >> num[i];
  }
  for(int i=0; i<4; i++){
    cin >> oper[i];
  }

  dfs(num[0], 1);

  sort(ans.begin(), ans.end());

  cout << ans[ans.size()-1] << '\n' << ans[0];
}