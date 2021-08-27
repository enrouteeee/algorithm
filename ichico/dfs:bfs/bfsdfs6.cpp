  //감시 피하기
  #include <iostream>
  #include <vector>
  #include <queue>

  using namespace std;

  int N;
  int board[7][7]; // 0-빈 1-학생 2-선생 3-장애물

  bool check(int i_, int j_);

  int ans;
  void dfs(int i_, int j_, int h){
    if(ans == 1)
      return;

    if(h == 3){
      int flag = 1;
      for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
          if(board[i][j] == 2){
            if(!check(i, j)){
              flag = 0;
              break;
            }
          }
        }
        if(flag == 0)
          break;
      }
      if(flag){
        ans = 1;
      }

      return;
    }

    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        if(i < i_)
          continue;
        if(i == i_ && j <= j_)
          continue;

        if(board[i][j] != 0)
          continue;
        board[i][j] = 3;
        dfs(i,j,h+1);
        board[i][j] = 0;
      }
    }
  }


  bool check(int i_, int j_){
    for(int i=i_-1; i>=0; i--){
      if(board[i][j_] == 1)
        return false;
      else if(board[i][j_] == 3)
        break;
    }

    for(int i=i_+1; i<N; i++){
      if(board[i][j_] == 1)
        return false;
      else if(board[i][j_] == 3)
        break;
    } 

    for(int j=j_-1; j>=0; j--){
      if(board[i_][j] == 1)
        return false;
      else if(board[i_][j] == 3)
        break;
    }

    for(int j=j_+1; j<N; j++){
      if(board[i_][j] == 1)
        return false;
      else if(board[i_][j] == 3)
        break;
    }

    return true;
  }

  int main(){

    cin >> N;

    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        char c;
        cin >> c;
        if(c == 'X'){
          board[i][j] = 0;
        }
        else if(c == 'S'){
          board[i][j] = 1;
        }
        else if(c == 'T'){
          board[i][j] = 2;
        }
      }
    }

    dfs(-1,-1,0);

    if(ans == 0)
      cout << "NO";
    else
      cout << "YES";

    return 0;
  }