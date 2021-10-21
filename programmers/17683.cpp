#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string change(string s){
    string m_ = "";
    for(int i=0; i<s.size(); i++){
        if(s[i] == '#'){
            m_[m_.size()-1] = (m_[m_.size()-1] + 10);
            continue;
        }
        m_ += s[i];
    }
    return m_;
}

int subTime(string s1, string s2){
    int s2t = stoi(s2.substr(0,2))*60 + stoi(s2.substr(3,2));
    int s1t = stoi(s1.substr(0,2))*60 + stoi(s1.substr(3,2));

    return s2t - s1t;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";

    m = change(m);

    vector<pair<int,string>> answers;
    for(int i=0; i<musicinfos.size(); i++){
        string tmp = musicinfos[i];
        string info[4];
        int cnt = 0;
        string t = "";
        int j = 0;
        for(; j<tmp.size(); j++){
            if(tmp[j] == ','){
                info[cnt++] = t;
                t = "";
                continue;
            }
            t += tmp[j];
        }
        info[cnt] = t;

        int time = subTime(info[0], info[1]);
        info[3] = change(info[3]);

        string newM = "";
        for(int i=0; i<time; i++){
            int idx = i % info[3].size();
            newM += info[3][idx];
        }

        if(m.size() > newM.size())
            continue;

        for(int i=0; i<=newM.size()-m.size(); i++){
            if(m == newM.substr(i,m.size()))
                answers.push_back({-time, info[2]});
        }
    }
    if(answers.size() == 0)
        return "(None)";

    stable_sort(answers.begin(), answers.end());

    return answers[0].second;
}