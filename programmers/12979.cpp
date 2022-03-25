#include <iostream>
#include <vector>
using namespace std;

int modUp(int a, int b){
    if(a % b){
        return a/b + 1;
    } else {
        return a/b;
    }
}

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;

    int point = 1;
    for(int i=0; i<stations.size(); i++){
        int tmp = stations[i]-w-point;
        if(tmp > 0)
            answer += modUp(tmp, 2*w+1);

        point = stations[i] + w + 1;
    }
    if(n >= point){
        int tmp = n-point+1;
        answer += modUp(tmp, 2*w+1);
    }

    return answer;
}