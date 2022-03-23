#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<string, string> graph;
map<string, int> income;

void distributeIncome(string seller, int money) {
    if(money == 0)
        return;
    int money10 = money / 10;
    int money90 = money - money10;

    if(graph[seller] != "-"){
        distributeIncome(graph[seller], money10);
    }
    income[seller] += money90;
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;

    for(int i=0; i<enroll.size(); i++){
        graph[enroll[i]] = referral[i];
    }


    for(int i=0; i<seller.size() ; i++){
        distributeIncome(seller[i], amount[i]*100);
    }

    for(int i=0; i<enroll.size(); i++){
        answer.push_back(income[enroll[i]]);
    }

    return answer;
}