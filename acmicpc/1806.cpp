#include <iostream>
#include <vector>

using namespace std;

int main(){

  int N, S;
  cin >> N >> S;

  vector<int> num;

  for(int i=0; i<N; i++){
    int a; cin >> a;
    num.push_back(a);
  }

  int left = 0;
  int right = 0;
  int tmp = num[0];

  int ans = 987654321;
  while(1){
    if(tmp < S){
      if(right < num.size()-1){
        right++;
        tmp += num[right];
      }
      else
        break;
    }
    else if(tmp >= S){
      if(ans > right-left + 1)
        ans = right-left +1;

      if(left < right){
        tmp -= num[left];
        left++;
      }
      else if(left == right){
        break;
      }
    }
  }

  if(ans == 987654321){
    cout << 0;
    return 0;
  }

  cout << ans;

  return 0;
}