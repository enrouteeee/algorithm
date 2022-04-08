#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    
    set<pair<long long,long long>> points;  // 교점의 좌표들
    for(int i=0; i<line.size()-1; i++){
        for(int j=i+1; j<line.size(); j++){
            long long A, B, C, D, E, F;
            A = (long long)line[i][0];
            B = (long long)line[i][1];
            C = (long long)line[j][0];
            D = (long long)line[j][1];
            E = (long long)line[i][2];
            F = (long long)line[j][2];
            
            long long BFED = B*F - E*D;
            long long ECAF = E*C - A*F;
            long long ADBC = A*D - B*C;
            
            if(ADBC == 0 || BFED % ADBC || ECAF % ADBC)
                continue;
            
            long long x = BFED / ADBC;
            long long y = ECAF / ADBC;
            
            points.insert({x,y});
        }
    }
    
    long long max_x = -1e15;
    long long max_y = -1e15;
    long long min_x = 1e15;
    long long min_y = 1e15;
    
    for(auto iter=points.begin(); iter!=points.end(); iter++){
        pair<long long,long long> tmp_p = *iter;
        if(max_x < tmp_p.first){
            max_x = tmp_p.first;
        }
        if(max_y < tmp_p.second){
            max_y = tmp_p.second;
        }
        if(min_x > tmp_p.first){
            min_x = tmp_p.first;
        }
        if(min_y > tmp_p.second){
            min_y = tmp_p.second;
        }
    }
    
    for(long long i=min_y; i<=max_y; i++){
        string tmp_s = "";
        for(long long j=min_x; j<=max_x; j++){
            tmp_s += ".";
        }
        answer.push_back(tmp_s);
    }
    
    for(auto iter=points.begin(); iter!=points.end(); iter++){
        pair<long long, long long> p = *iter;
        answer[max_y - p.second][p.first - min_x] = '*';
    }
    
    
    return answer;
}