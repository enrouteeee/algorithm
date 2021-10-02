#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int main(){

  string s;
  cin >> s;
  
  stack<pair<char, int>> st;

  for(int i=0; i<s.size(); i++){
    if(s[i] == ')'){
      int cnt = 0;
      while(st.top().first != '('){
        cnt += st.top().second;
        st.pop();
      }
      st.pop();
      int K = st.top().first - '0';
      st.pop();
      st.push(make_pair(1, cnt*K));
    }
    else{
      st.push(make_pair(s[i], 1));
    }
  }

  int ans = 0;
  while(!st.empty()){
    ans += st.top().second;
    st.pop();
  }

  cout << ans;

  return 0;
}