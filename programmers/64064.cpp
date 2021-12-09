#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<string> user_id;
vector<string> banned_id;

int n;
int visit[10];
set<string> answer;

void dfs(int h){
    if(h == n){
        string tmp = "";
        for(int i=0; i<user_id.size(); i++){
            tmp += to_string(visit[i]);
        }
        answer.insert(tmp);
        return;
    }
    
    for(int i=0; i<user_id.size(); i++){
        if(visit[i])
            continue;
        
        if(banned_id[h].size() != user_id[i].size())
            continue;
        
        int flag = 1;
        for(int s=0; s<banned_id[h].size(); s++){
            if(banned_id[h][s] == '*')
                continue;
            if(banned_id[h][s] != user_id[i][s]){
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            visit[i] = 1;
            dfs(h+1);
            visit[i] = 0;
        }
    }
}

int solution(vector<string> user_id_, vector<string> banned_id_) {
    user_id = user_id_;
    banned_id = banned_id_;
    n = banned_id.size();
    
    dfs(0);
    
    return answer.size();
}