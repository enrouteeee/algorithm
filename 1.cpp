//nhn pre-test 1차 기출문제
/*
문제
모든 원소가 0 또는 1 인 행렬이 있습니다. 1 로 표시된 원소는 영역을 나타냅니다. 여기에서 상하좌우에 인접한 1
은 같은 영역이라고 가정합니다. 각 영역의 크기는 1 의 개수로 정의합니다. 주어진 N x N 크기의 행렬에서 영역의
개수와 각 영역의 크기를 오름차순으로 출력하세요.
[입력]
• 첫 번째 행은 행렬의 크기인 N입니다. N 은 1 이상 10 이하의 자연수입니다.
• 입력 두 번째 행부터는 공백으로 구분된 0 과 1 로 행렬이 주어집니다. 각 행은 개행 문자(newline, \n)로
구분됩니다.
[출력]
• 첫 번째 행은 영역의 개수를 출력합니다.
• 두 번째 행은 각 영역의 크기를 공백으로 구분하여 오름차순으로 출력합니다.
• 한 행의 끝은 불필요한 공백 없이 개행 문자(newline, \n)로 끝나야 합니다.
• 영역이 존재하지 않을 경우 영역 수 0으로 1 행으로만 출력합니다.
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int N;
int board[10][10];
int visit[10][10];

int area(int i, int j){
  int result = 0;
  queue<pair<int, int>> q;

  q.push(make_pair(i,j));

  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    if(visit[x][y] == 1)
      continue;

    visit[x][y] = 1;
    result++;

    for(int d=0; d<4; d++){
      int nx = x+dx[d];
      int ny = y+dy[d];

      if(nx < 0 || nx >= N || ny < 0 || ny >= N)
        continue;

      if(board[nx][ny] == 1 && visit[nx][ny] == 0)
        q.push(make_pair(nx,ny));
    }
  }

  return result;
}

int main(){

  cin >> N;

  vector<int> ans;
  
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      cin >> board[i][j];
    }
  }

  for(int i=0;i<N; i++){
    for(int j=0; j<N; j++){
      if(board[i][j] == 0 || visit[i][j])
        continue;
      
      ans.push_back(area(i,j));
    }
  }

  sort(ans.begin(), ans.end());

  cout << ans.size() << '\n';
  for(int i=0; i<ans.size(); i++){
    cout << ans[i] << " ";
  }

  return 0;
}