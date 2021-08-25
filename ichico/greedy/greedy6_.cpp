#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool cmp(pair<int,int> p1, pair<int,int> p2){
    return p1.second < p2.second;
}

int solution(vector<int> food_times, long long k) {
    int answer = 0;

    long long sum = 0;
    priority_queue<pair<int,int>> pq;
    for(int i=0; i<food_times.size(); i++){
        pq.push(make_pair(-food_times[i], i+1));
        sum += food_times[i];
    }

    if(sum <= k){
        return -1;
    }

    sum = 0;
    long long cnt = 0;
    int num = food_times.size();
    while(sum + (-pq.top().first - cnt)*num <= k){
        sum += (-pq.top().first - cnt) * num;
        cnt = -pq.top().first;
        pq.pop();
        num--;
    }

    vector<pair<int,int>> ft;
    while(!pq.empty()){
        ft.push_back(make_pair(pq.top().first, pq.top().second));
        pq.pop();
    }

    sort(ft.begin(), ft.end(), cmp);


    return ft[(k-sum) % num].second;
}