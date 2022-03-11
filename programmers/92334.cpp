#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;

    map<string, set<string>> m;
    map<string, int> ans;
    for(int i=0; i<report.size(); i++){
        string p1, p2;
        for(int j=0; j<report[i].size(); j++){
            if(report[i][j] == ' '){
                p1 = report[i].substr(0, j);
                p2 = report[i].substr(j+1);
                break;
            }
        }
        m[p2].insert(p1);
    }

    for(auto i=m.begin(); i!=m.end(); i++){
        if(i->second.size() >= k) {
            for(auto j=i->second.begin(); j!=i->second.end(); j++){
                ans[*j]++;
            }
        }
    }

    for(int i=0; i<id_list.size(); i++){
        answer.push_back(ans[id_list[i]]);
    }

    return answer;
}