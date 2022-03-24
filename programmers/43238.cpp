#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    
    long long left = 1;
    long long right = (long long) times[times.size()-1] * n;
    long long middle;
    while(left <= right) {
        middle = (left + right) / 2;
        long long count = 0;
        for(int i=0; i<times.size() ;i++){
            count += middle / times[i];
        }
        
        if(count < n){
            left = middle + 1;
        } else {
            if(middle <= right)
                answer = middle;
            right = middle-1;
        }
    }
    
    return answer;
}