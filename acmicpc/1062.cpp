#include <string>
#include <vector>
#include <iostream>

using namespace std;

int spell[26];
int N, K;
vector<string> strs;

int ans;

void dfs(int i_, int h){
  if(h == K){
    int cnt = 0;
    for(int i=0; i<N; i++){
      int flag = 1;
      for(int j=0; j<strs[i].size(); j++){
        int a = strs[i][j] - 'a';
        if(spell[a] == 0){
          flag = 0;
          break;
        }
      }
      if(flag == 1){
        cnt++;
      }
    }

    if(ans < cnt)
      ans = cnt;

    return;
  }

  for(int i=i_; i<26; i++){
    if(spell[i])
      continue;
    spell[i]++;
    dfs(i+1, h+1);
    spell[i]--;
  }
}

int main(){
  
  cin >> N >> K;

  if(K < 5){
    cout << 0;
    return 0;
  }

  spell['a'-'a'] = 1;
  spell['n'-'a'] = 1;
  spell['t'-'a'] = 1;
  spell['i'-'a'] = 1;
  spell['c'-'a'] = 1;
  K -= 5;

  for(int i=0; i<N; i++){
    string str = "";
    cin >> str;
    strs.push_back(str);
  }

  dfs(0, 0);

  cout << ans;

  return 0;
}