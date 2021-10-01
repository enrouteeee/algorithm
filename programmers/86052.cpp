//https://programmers.co.kr/learn/courses/30/lessons/86052
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> grid;
int visit[500][500][4];
int N, M;

//동 북 서 남
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int simulation(int i, int j, int d){
    int nx = (i + dx[d] + N) % N;
    int ny = (j + dy[d] + M) % M;
    
    
    if(visit[nx][ny][d])
        return -1;
    
    int cnt = 0;
    while(visit[nx][ny][d] == 0){
        visit[nx][ny][d] = 1;
        if(grid[nx][ny] == 'S'){
            nx = (nx + dx[d] + N) % N;
            ny = (ny + dy[d] + M) % M;
        }
        else if(grid[nx][ny] == 'L'){
            d = (d+1) % 4;
            nx = (nx + dx[d] + N) % N;
            ny = (ny + dy[d] + M) % M;
        }
        else if(grid[nx][ny] == 'R'){
            d = (d+3) % 4;
            nx = (nx + dx[d] + N) % N;
            ny = (ny + dy[d] + M) % M;
        }
        
        cnt++;
    }
    
    return cnt;
}

vector<int> solution(vector<string> grid_) {
    grid = grid_;
    vector<int> answer;
    N = grid.size();
    M = grid[0].size();
    
    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[i].size(); j++){
            for(int d=0; d<4; d++){
                int s_tmp = simulation(i, j, d);
                if(s_tmp != -1)
                    answer.push_back(s_tmp);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}