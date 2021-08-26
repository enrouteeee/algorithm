//럭키스트레이트
#include <iostream>
#include <vector>

using namespace std;

int main(){

  int N;
  vector<int> num;

  cin >> N;

  while(N){
    num.push_back(N % 10);
    N/=10;
  }

  int sum0 = 0;
  int sum1 = 0;
  for(int i=0; i<num.size(); i++){
    if(i < num.size()/2){
      sum0 += num[i];
    }
    else {
      sum1 += num[i];
    }
  }

  if(sum0 == sum1){
    cout << "LUCKY";
  }
  else{
    cout << "READY";
  }

  return 0;
}