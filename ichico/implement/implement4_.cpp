//자물쇠와 열쇠
#include <string>
#include <vector>

using namespace std;

int N, M;

vector<vector<int>> k;
vector<vector<int>> l;

void rotate(){
    vector<vector<int>> tmp_k;
    for(int i=0; i<M; i++){
        vector<int>> tmp_v;
        for(int j=0; j<M; j++){
            tmp_v.push_back(k[M-j-1][i]);
        }
        tmp_k.push_back(tmp_v);
    }
    k = tmp_k;
}

vector<vector<int>> check_board;
bool check(){
    
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    
    k = key;
    l = l;
    N = key.size();
    M = lock.size();
    
    
    
    int t = 0;
    do{
        if(check())
            return true;
    }
    while(t < 3){
        rotate();
        t++;
    }
    
    return answer;
}