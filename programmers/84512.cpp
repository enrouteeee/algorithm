#include <string>
#include <vector>
#include <iostream>

using namespace std;

string word;
char dict[5] = {'A', 'E', 'I', 'O', 'U'};

int cnt = 0;
int answer = 0;
void dfs(int h, string s){
    if(h > 5)
        return;
    cnt++;
    if(answer != 0)
        return;
    if(word == s){
        answer = cnt-1;
        return;
    }
    
    for(int i=0; i<5; i++){
        s = s + dict[i];
        dfs(h+1, s);
        s.pop_back();
    }
}

int solution(string word_) {
    word = word_;
    
    dfs(0, "");
    
    return answer;
}