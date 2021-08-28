//실패율
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

double s[502];
double c[502];
bool cmp(int n1, int n2){
    if(c[n1] == 0 && c[n2] == 0) return n1 < n2;
    else if(c[n1] == 0) return false;
    else if(c[n2] == 0) return true;
    double c1 = s[n1]/c[n1];
    double c2 = s[n2]/c[n2];
    if(c1 == c2)
        return n1 < n2;
    return c1 > c2;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    for(int i=1; i<=N; i++)
        answer.push_back(i);
    
    for(int i=0; i<stages.size(); i++){
        s[stages[i]]++;
        for(int j=1; j<=stages[i]; j++){
            c[j]++;
        }
    }
    
    sort(answer.begin(), answer.end(), cmp);
    
    return answer;
}