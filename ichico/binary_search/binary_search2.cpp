//고정점 찾기
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){

  int N;
  vector<int> num;

  cin >> N;
  for(int i=0; i<N; i++){
    int a;
    cin >> a;
    num.push_back(a);
  }

  int left = 0;
  int right = N-1;

  int ans = -1;
  while(left <= right){
    int middle = (left + right) / 2;
    if(middle == num[middle]){
      ans = middle;
      break;
    }
    else if(middle < num[middle]){
      right = middle-1;
    }
    else if(middle > num[middle]){
      left = middle+1;
    }
  }

  cout << ans;

  return 0;
}