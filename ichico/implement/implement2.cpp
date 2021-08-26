//문자열 재정렬
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

  string s;

  cin >> s;

  int sum = 0;
  vector<char> ans;
  for(int i=0; i<s.size(); i++){
    if(s[i] >= 80 && s[i] <= 89){
      sum += s[i] - '0';
    }
    else{
      ans.push_back(s[i]);
    }
  }

  sort(s.begin(), s.end());

  for(int i=0; i<ans.size(); i++)
    cout << ans[i];
  if(sum != 0) cout << sum;

  return 0;
}