#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    if(cacheSize == 0)
        return cities.size()*5;
    
    vector<pair<int,string>> cv;
    for(int i=0; i<cities.size(); i++){
        //소문자 변환
        for(int j=0; j<cities[i].size(); j++){
            cities[i][j] = tolower(cities[i][j]);
        }
            
        //캐시 힛 성공
        int flag = 0;
        for(int j=0; j<cv.size(); j++){
            if(cities[i] == cv[j].second){
                flag = 1;
                cv[j].first = i;
                break;
            }
        }
        if(flag == 1){
            answer += 1;
            continue;
        }
        
        //캐시 힛 실패
        
        //캐시에 넣는 경우
        if(cv.size() < cacheSize){
            cv.push_back({i,cities[i]});
            answer += 5;
            continue;
        }
        
        //캐시에서 빼고 넣는 경우    
        int minj = 0;
        int min = 987654321;
        for(int j=0; j<cv.size(); j++){
            if(min > cv[j].first){
                min = cv[j].first;
                minj = j;
            }
        }
        cv.erase(cv.begin()+minj);
        cv.push_back({i,cities[i]});
        answer += 5;
    }
    
    return answer;
}