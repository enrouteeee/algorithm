//탑승구
#include <iostream>
#include <vector>

using namespace std;

int gs[100001];

int pushG(int a){
  if(a == 0)
    return -1;

  if(gs[a]){
    return pushG(a-1);
  }
  else{
    gs[a] = 1;
    return 0;
  }
}

int main(){

  int G, P;
  cin >> G >> P;

  int cnt = 0;
  for(int i=0; i<P; i++){
    int a;
    cin >> a;
    if(pushG(a) == -1)
      break;
    cnt++;
  }

  cout << cnt << '\n';

  return 0;
}