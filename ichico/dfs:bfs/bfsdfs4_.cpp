//괄호변환
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int check(string s){
    int cnt = 0;
    int flag = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '('){
            cnt++;
        }
        else if(s[i] == ')'){
            cnt--;
            if(cnt < 0){
                flag = 1;
            }
        }
    }
    if(cnt == 0){
        if(flag == 1)
            return 0;   // 균형잡힌
        else if(flag == 0)
            return 1;   // 올바른
    }
    else
        return 2;   // X
}

string sol(string p){
    string u, v;
    if(p.size() == 0)
        return "";
    
    for(int i=2; i<=p.size(); i+=2){
        u = p.substr(0, i);
        v = p.substr(i, p.size()-i);
        if(check(u) == 2)
            continue;
        if(check(u) == 0 || check(u) == 1){
            break;
        }
    }
    
    if(check(u) == 1){
        return u + sol(v);
    }
    else if(check(u) == 0){
        v = sol(v);
        string answer = "";
        answer += '(';
        answer += v;
        answer += ')';
        for(int i=1; i<u.size()-1; i++){
            if(u[i] == '('){
                answer += ')';
            }
            else if(u[i] == ')'){
                answer += '(';
            }
        }
        return answer;
    }
    
    return "";
}

string solution(string p) {
    string answer = "";
    
    if(check(p) == 1)
        return p;
    
    return sol(p);
}

/*
// "균형잡힌 괄호 문자열"의 인덱스 반환
int balancedIndex(string p) {
    int count = 0; // 왼쪽 괄호의 개수
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == '(') count += 1;
        else count -= 1;
        if (count == 0) return i;
    }
    return -1;
}

// "올바른 괄호 문자열"인지 판단
bool checkProper(string p) {
    int count = 0; // 왼쪽 괄호의 개수
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == '(') count += 1;
        else {
            if (count == 0) { // 쌍이 맞지 않는 경우에 false 반환
                return false;
            }
            count -= 1;
        }
    }
    return true; // 쌍이 맞는 경우에 true 반환
}

string solution(string p) {
    string answer = "";
    if (p == "") return answer;
    int index = balancedIndex(p);
    string u = p.substr(0, index + 1);
    string v = p.substr(index + 1);
    // "올바른 괄호 문자열"이면, v에 대해 함수를 수행한 결과를 붙여 반환
    if (checkProper(u)) {
        answer = u + solution(v);
    }
    // "올바른 괄호 문자열"이 아니라면 아래의 과정을 수행
    else {
        answer = "(";
        answer += solution(v);
        answer += ")";
        u = u.substr(1, u.size() - 2); // 첫 번째와 마지막 문자를 제거
        for (int i = 0; i < u.size(); i++) {
            if (u[i] == '(') u[i] = ')';
            else u[i] = '(';
        }
        answer += u;
    }
    return answer;
}
*/