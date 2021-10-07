#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<vector<int>> scores) {
    string answer = "";
    int size = scores.size();
    
    int check[11] = {0,};
    for(int j=0; j<size; j++){
        vector<int> tmp;
        for(int i=0; i<size; i++){
            tmp.push_back(scores[i][j]);
        }
        sort(tmp.begin(), tmp.end());
        
        if(tmp[size-1] == scores[j][j] && tmp[size-2] != tmp[size-1]){
            scores[j][j] = -1;
        }
        else if(tmp[0] == scores[j][j] && tmp[0] != tmp[1]){
            scores[j][j] = -1;
        }
    }
    
    for(int j=0; j<size; j++){
        int cnt = 0;
        int sum = 0;
        for(int i=0; i<size; i++){
            if(scores[i][j] == -1)
                continue;
            
            cnt++;
            sum += scores[i][j];
        }
        if( sum/cnt >= 90 ){
            answer += "A";
        }
        else if( sum/cnt >= 80){
            answer += "B";
        }
        else if( sum /cnt >= 70){
            answer += "C";
        }
        else if( sum/cnt >= 50){
            answer += "D";
        }
        else {
            answer += "F";
        }
    }
    
    
    return answer;
}