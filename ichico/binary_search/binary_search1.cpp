//정렬된 배열에서 특정 수의 개수 구하기
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){

  int N, X;
  cin >> N >> X;

  vector<int> num;
  for(int i=0; i<N; i++){
    int a;
    cin >> a;
    num.push_back(a);
  }

  int ans = upper_bound(num.begin(), num.end(), X) - lower_bound(num.begin(), num.end(), X);

  if(ans == 0)
    cout << -1;
  else
    cout << ans;

  return 0;
}