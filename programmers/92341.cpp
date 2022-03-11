#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int> ans;
    map<string, pair<int, int>> m;
    
    for(int i=0; i<records.size(); i++){
        string carNumber = records[i].substr(6,4);
        int time = stoi(records[i].substr(0,2))*60 + stoi(records[i].substr(3,2));
        
        if(records[i].substr(11) == "IN"){
            m[carNumber] = {time, 1};
        }
        else if(records[i].substr(11) == "OUT"){
            ans[carNumber] += time - m[carNumber].first;
            m[carNumber] = {time, 0};
        }
    }
    
    for(auto iter = m.begin(); iter != m.end(); iter++){
        if(iter->second.second == 1){
            ans[iter->first] += 24*60 - 1 - iter->second.first;
        }
    }
    
    for(auto iter = ans.begin(); iter != ans.end(); iter++){
        int cost = iter->second;
        if(fees[0] >= cost){
            answer.push_back(fees[1]);
        } else {
            if((cost - fees[0]) % fees[2]){
                answer.push_back(fees[1] + (((cost - fees[0]) / fees[2]) + 1) * fees[3]);
            }
            else {
                answer.push_back(fees[1] + ((cost-fees[0]) / fees[2]) * fees[3]);
            }
        }
    }
    
    return answer;
}