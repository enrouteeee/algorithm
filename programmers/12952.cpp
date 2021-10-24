#include <string>
#include <vector>
#include <iostream>

using namespace std;

int N;
int answer;

int check1[12]; // 행 체크
int check2[23]; // 대각선 1 체크
int check3[23]; // 대각선 2 체크

void dfs(int h){if(h == N){
        answer++;
        return;
    }
    for(int i=0; i<N; i++){
        if(check1[i] || check2[i+h] || check3[i-h + N-1])
            continue;
        check1[i] = 1;
        check2[i+h] = 1;
        check3[i-h + N-1] = 1;
        
        dfs(h+1);
        
        check1[i] = 0;
        check2[i+h] = 0;
        check3[i-h + N-1] = 0;
    }
}


int solution(int n) {
    N = n;
    
    dfs(0);
    
    return answer;
}