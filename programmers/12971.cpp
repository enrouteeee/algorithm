#include <iostream>
#include <vector>
using namespace std;

int dp[100001];
int dp2[100001];
int solveDp(vector<int> v) {
    dp[0] = v[0];
    dp2[0] = v[0];
    if(v.size() > 1){
        dp[1] = v[1];
        dp2[1] = max(v[0], v[1]);
    }
    for(int i=2; i<v.size(); i++){
        dp[i] = v[i] + dp2[i-2];
        dp2[i] = max(dp[i], dp2[i-1]);
    }

    return dp2[v.size()-1];
}

int solution(vector<int> sticker)
{
    int answer =0;

    if(sticker.size() == 1){
        return sticker[0];
    } else if(sticker.size() == 2){
        return max(sticker[0], sticker[1]);
    } else if(sticker.size() == 3){
        return max(sticker[0], max(sticker[1], sticker[2]));
    }

    vector<int> v1;
    for(int i=2; i<sticker.size()-1; i++){
        v1.push_back(sticker[i]);
    }

    vector<int> v2;
    for(int i=1; i<sticker.size()-2; i++){
        v2.push_back(sticker[i]);
    }

    vector<int> v3;
    for(int i=1; i<sticker.size()-1; i++){
        v3.push_back(sticker[i]);
    }

    answer = max(sticker[0] + solveDp(v1), sticker[sticker.size()-1] + solveDp(v2));
    answer = max(answer, solveDp(v3));

    return answer;
}