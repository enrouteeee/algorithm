#include <string>
#include <vector>
#include <set>

using namespace std;

set<int> operation(int a, int b){
    set<int> result;
    result.insert(a + b);
    result.insert(a - b);
    result.insert(a * b);
    if(b)
        result.insert(a / b);
    
    return result;
}

int solution(int N, int number) {
    if(N == number)
        return 1;
    
    int answer = 0;
    set<int> dp[9];
    
    int tmp = 0;
    for(int i=1; i<=9; i++){
        tmp = tmp*10 + N;
        if(tmp == number){
            return i;
        }
        dp[i].insert(tmp);
    }
    
    bool flag = false;
    for(int i=2; i<=8; i++){
        for(int j=1; j<i; j++){
            for(auto x=dp[j].begin(); x!=dp[j].end(); x++){
                for(auto y=dp[i-j].begin(); y!=dp[i-j].end(); y++){
                    set<int> s_tmp = operation(*x, *y);
                    
                    for(auto st=s_tmp.begin(); st!=s_tmp.end(); st++){
                        dp[i].insert(*st);
                        if(*st == number){
                            answer = i;
                            flag = true;
                            break;
                        }
                    }
                    if(flag)
                        break;
                }
                if(flag)
                    break;
            }
            if(flag)
                break;
        }
        if(flag)
            break;
    }
    
    if(flag)
        return answer;
    else
        return -1;
}