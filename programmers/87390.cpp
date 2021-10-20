#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    int x = left / n;
    int y = left % n;

    for(long long i = left; i <= right; i++){
        long long x = (i / n) +1;
        long long y = (i % n) +1;

        if(x > y)
            answer.push_back(x);
        else
            answer.push_back(y);
    }

    return answer;
}