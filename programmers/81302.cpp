//https://programmers.co.kr/learn/courses/30/lessons/81302#fn1
#include <string>
#include <vector>

using namespace std;

int dx1[4] = {0, 0, 1, -1};
int dy1[4] = {1, -1, 0, 0};

int dx2[8] = {-2, -1, -1, 0, 0, 1, 1, 2};
int dy2[8] = {0, -1, 1, -2, 2, -1, 1, 0};

int board[5][5];

bool check(int i, int j){
    int nx, ny;
    //거리 1인 경우
    for(int d=0; d<4; d++){
        nx = i+dx1[d];
        ny = j+dy1[d];
        if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
            continue;
        
        if(board[nx][ny] == 1)
            return false;
    }
    //거리 2인 경우
    for(int d=0; d<8; d++){
        nx = i+dx2[d];
        ny = j+dy2[d];
        if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
            continue;
        
        if(d == 0 && board[nx][ny] == 1){
            if(board[nx+1][ny] != 2)
                return false;
        }
        else if(d == 1 && board[nx][ny] == 1){
            if(!(board[nx+1][ny] == 2 && board[nx][ny+1] == 2))
                return false;
        }
        else if(d == 2 && board[nx][ny] == 1){
            if(!(board[nx+1][ny] == 2 && board[nx][ny-1] == 2))
                return false;
        }
        else if(d == 3 && board[nx][ny] == 1){
            if(board[nx][ny+1] != 2)
                return false;
        }
        else if(d == 4 && board[nx][ny] == 1){
            if(board[nx][ny-1] != 2)
                return false;
        }
        else if(d == 5 && board[nx][ny] == 1){
            if(!(board[nx-1][ny] == 2 && board[nx][ny+1] == 2))
                return false;
        }
        else if(d == 6 && board[nx][ny] == 1){
            if(!(board[nx-1][ny] == 2 && board[nx][ny-1] == 2))
                return false;
        }
        else if(d == 7 && board[nx][ny] == 1){
            if(board[nx-1][ny] != 2)
                return false;
        }
    }
    
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int t=0; t<places.size(); t++){
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                char a = places[t][i][j];
                if(a == 'P'){
                    board[i][j] = 1;
                }
                else if(a == 'O'){
                    board[i][j] = 0;
                }
                else if(a == 'X'){
                    board[i][j] = 2;
                }
            }
        }
        
        int flag = 1;
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                if(board[i][j] == 1){
                    if(check(i,j) == false){
                        flag = 0;
                        break;
                    }
                }
            }
            if(flag == 0)
                break;
        }
        answer.push_back(flag);
    }
    
    return answer;
}