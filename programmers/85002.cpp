#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> weights;
vector<string> head2head;
vector<double> rate;
int weight_win[1001];

bool cmp(int a, int b){
    if(rate[a]== rate[b]){
        if(weight_win[a] == weight_win[b]){
            if(weights[a] == weights[b]){
                return a < b;
            }
            return weights[a] > weights[b];
        }
        return weight_win[a] > weight_win[b];
    }
    return rate[a] > rate[b];
}

vector<int> solution(vector<int> weights_, vector<string> head2head_) {
    weights = weights_;
    head2head = head2head_;
    int N = weights.size();
    
    for(int i=0; i<N; i++){
        double cnt = 0;
        double win_n = 0;
        for(int j=0; j<N; j++){
            if(i == j)
                continue;
            if(head2head[i][j] == 'W'){
                win_n++;
                cnt++;
                if(weights[i] < weights[j]){
                    weight_win[i]++;
                }
            }
            else if(head2head[i][j] == 'L'){
                cnt++;
            }
        }
        if(cnt == 0){
            rate.push_back(0);
        }
        else{
            rate.push_back(win_n/cnt);
        }
    }
    
    
    vector<int> answer;
    for(int i=0; i<N; i++)
        answer.push_back(i);
    
    sort(answer.begin(), answer.end(), cmp);
    
    for(int i=0; i<N; i++)
        answer[i]++;
    
    return answer;
}