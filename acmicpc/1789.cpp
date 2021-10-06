#include <vector>
#include <iostream>

using namespace std;

int main(){

  long long S;
  cin >> S;

  long long i, tmp = 0;
  for(i=1;tmp <= S;i++){
    tmp += i;
  }
  cout << i-2;
  return 0;
}