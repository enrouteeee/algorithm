#include <string>
#include <vector>
#include <iostream>

using namespace std;

int parent[101];

void init(){
    for(int i=0; i<101; i++){
        parent[i] = i;
    }
}

int findP(int a){
    if(a == parent[a])
        return a;
    return parent[a] = findP(parent[a]);
}

void uni(int a, int b){
    a = findP(a);
    b = findP(b);
    if(a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

int sub(int a, int b){
    return (a > b) ? a-b : b-a;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 100;
    
    for(int i=0; i<n-1; i++){
        init();
        int num1 = 0;
        int num2 = 0;
        for(int j=0; j<n-1; j++){
            if(i == j)
                continue;
            uni(wires[j][0], wires[j][1]);
        }
        
        int num[2] = {0, 0};
        int tmp = findP(1);
        num[0] = 1;
        for(int j=2; j<=n; j++){
            if(findP(j) != tmp)
                num[1]++;
            else
                num[0]++;
        }
        if(answer > sub(num[0], num[1]))
            answer = sub(num[0], num[1]);
    }
    
    return answer;
}