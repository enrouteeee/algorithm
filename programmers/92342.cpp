#include <string>
#include <vector>
#include <iostream>

using namespace std;

int tmp[11];
int n;
vector<int> info;
int m = 0;
vector<int> answer;
void dfs(int h, int i_){
    if(h == n) {
        int sum1 = 0;
        int sum2 = 0;
        for(int i=0; i<=10; i++){
            if(info[i] == 0 && tmp[i] == 0)
                continue;
            if(info[i] < tmp[i]){
                sum1 += 10 - i;
            }
            else {
                sum2 += 10 - i;
            }
        }
        
        int sub = sum1 - sum2;
        if(sub <= 0 || sub < m)
            return;
        
        if(sub > m) {
            m = sub;
            for(int i=0; i<=10; i++){
                answer[i] = tmp[i];
            }
        }
        else if(sub == m) {
            int flag = 0;
            for(int i=10; i>=0; i--){
                if(answer[i] && tmp[i] == 0){
                    flag = 0;
                    break;
                }
                else if(answer[i] == 0 && tmp[i]){
                    flag = 1;
                    break;
                }
                if(answer[i] < tmp[i]){
                    flag = 1;
                    break;
                }
            }
            if(flag) {
                for(int i=0; i<=10; i++){
                    answer[i] = tmp[i];
                }
            }
        }
        return;
    }
    
    for(int i=i_; i<=10; i++){
        tmp[i]++;
        dfs(h+1, i);
        tmp[i]--;
    }
}

vector<int> solution(int n_, vector<int> info_) {
    n = n_;
    info = info_;
    
    for(int i=0; i<=10; i++){
        answer.push_back(0);
    }
    dfs(0, 0);
    
    if(m == 0) return {-1};
    
    return answer;
}