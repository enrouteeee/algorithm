//https://programmers.co.kr/learn/courses/30/lessons/77885#
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(int i=0; i<numbers.size(); i++){
        long long tmp = numbers[i];
        
        if(numbers[i] % 2 == 0){
            answer.push_back(numbers[i] + 1);
            continue;
        }
        
        int cnt = 0;
        while(tmp){
            int a = tmp%2;
            if(a == 0){
                break;
            }
            tmp /= 2;
            cnt++;
        }
        
        long long ans;
        
        ans = numbers[i] + pow(2, cnt-1);
        answer.push_back(ans);
    }
    
    return answer;
}