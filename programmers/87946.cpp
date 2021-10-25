#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = 0;
vector<vector<int>> dungeons;
int N;

int visit[8];
void dfs(int h, int p){
    if(answer < h)
        answer = h;

    for(int i=0; i<N; i++){
        if(visit[i] || dungeons[i][0] > p)
            continue;

        visit[i] = 1;
        dfs(h+1, p-dungeons[i][1]);
        visit[i] = 0;
    }
}

int solution(int k, vector<vector<int>> dungeons_) {
    dungeons = dungeons_;
    N = dungeons.size();

    dfs(0, k);

    return answer;
}