#include <string>
#include <vector>
#include <iostream>

#define INF 987654321

using namespace std;

int board[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i == j){
                board[i][j] = 0;
                continue;
            }
            board[i][j] = INF;
        }
    }
    
    for(int i=0; i<fares.size(); i++){
        board[fares[i][0]][fares[i][1]] = fares[i][2];
        board[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    
    
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
            }
        }
    }
    
    for(int i=1; i<=n; i++){
        if(board[s][i] == INF || board[i][a] == INF || board[i][b] == INF)
            continue;
        answer = min(answer, board[s][i] + board[i][a] + board[i][b]);
    }
    
    
    return answer;
}