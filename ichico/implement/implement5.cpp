//뱀
#include <iostream>
#include <vector>

using namespace std;

int N, K, L;
int board[101][101];
vector<pair<int,char>> lv;

int main(){
  
  cin >> N >> K;

  for(int i=0; i<K; i++){
    int a, b;
    cin >> a >> b;
    board[a][b] = 1;
  }

  cin >> L;
  for(int i=0; i<L; i++){
    int a;
    char c;
    cin >> a >> c;
    lv.push_back(make_pair(a,c));
  }

  


}