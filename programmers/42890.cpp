#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<string>> relation;
int visit[10];

bool check() {
    set<string> ss;

    for(int i=0; i<relation.size(); i++){
        string tmp = "";
        for(int j=0; j<relation[i].size(); j++){
            if(visit[j]){
                tmp += relation[i][j];
            }
        }
        ss.insert(tmp);
    }

    if(ss.size() == relation.size()){
        return true;
    } else { 
        return false;
    }
}

set<vector<int>> answers;
void dfs(int h, int i_) {
    if(check()){
        vector<int> tmp;
        for(int i=0; i<relation[0].size(); i++){
            if(visit[i])
                tmp.push_back(i);
        }
        for(auto iter=answers.begin() ;iter!=answers.end(); iter++){
            vector<int> vi = *iter;
            if(includes(vi.begin(), vi.end(), tmp.begin(), tmp.end())){
                answers.erase(iter);
            }
        }
        for(auto iter=answers.begin() ;iter!=answers.end(); iter++){
            vector<int> vi = *iter;
            if(includes(vi.begin(), vi.end(), tmp.begin(), tmp.end())){
                answers.erase(iter);
            }
        }
        answers.insert(tmp);
        return;
    }

    for(int i=i_; i<relation[0].size(); i++){
        visit[i] = 1;
        dfs(h+1, i+1);
        visit[i] = 0;
    }
}

int solution(vector<vector<string>> relation_) {
    relation = relation_;

    dfs(0, 0);

    return answers.size();
}