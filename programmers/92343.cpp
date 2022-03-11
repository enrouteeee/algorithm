#include <string>
#include <vector>
#include <iostream>

using namespace std;

int N;
int board[18][18];
vector<int> info;

int answer;
int visit[18][18][18];
vector<int> path;
//현재 위치, 양의 수, 늑대 수
void dfs(int c, int n1, int n2){
    if(answer < n1)
        answer = n1;
    
    for(int i=0; i<N; i++){
        if(!board[c][i])
            continue;
        
        if(info[i] == 0){
            info[i] = 2;
            n1++;
            visit[i][n1][n2] = 1;
            path.push_back(i);
            dfs(i, n1, n2);
            path.pop_back();
            visit[i][n1][n2] = 0;
            n1--;
            info[i] = 0;
        } else if(info[i] == 1) {
            if(n1 == n2+1)
                continue;
            info[i] = 2;
            n2++;
            visit[i][n1][n2] = 1;
            path.push_back(i);
            dfs(i, n1, n2);
            path.pop_back();
            visit[i][n1][n2] = 0;
            n2--;
            info[i] = 1;
        } else {
            if(visit[i][n1][n2])
                continue;
            visit[i][n1][n2] = 1;
            path.push_back(i);
            dfs(i, n1, n2);
            path.pop_back();
            visit[i][n1][n2] = 0;
        }
    }
}

int solution(vector<int> info_, vector<vector<int>> edges) {
    
    info = info_;
    N = info.size();
    
    for(int i=0; i<edges.size(); i++){
        board[edges[i][0]][edges[i][1]] = 1;
        board[edges[i][1]][edges[i][0]] = 1;
    }
    
    // 첫번째 노드에서 양 데리고 출발
    path.push_back(0);
    info[0] = 2;
    dfs(0, 1, 0);
    
    return answer;
}