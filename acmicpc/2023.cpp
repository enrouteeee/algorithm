#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

bool check(int num){
  for(int i=2; i<=sqrt(num); i++){
    if(num % i == 0)
      return false;
  }
  return true;
}

int main(){

  vector<vector<int>> v;

  v.push_back({2,3,5,7});

  int N;
  cin >> N;

  for(int i=1; i<N; i++){
    vector<int> tmp;
    for(int j=0; j<v[i-1].size(); j++){
      for(int k=1; k<10; k++){
        if(k % 2 == 0)
          continue;

        int tmp_n = v[i-1][j] * 10 + k;
        if(check(tmp_n))
          tmp.push_back(tmp_n);
      }
    }
    v.push_back(tmp);
  }

  for(int i=0; i<v[N-1].size(); i++)
    cout << v[N-1][i] << '\n';

  return 0;
}