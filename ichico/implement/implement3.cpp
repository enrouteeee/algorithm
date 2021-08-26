//문자열 압축
#include <string>
#include <vector>
using namespace std;

int solution(string s) {
    int answer = 1001;
    int len = s.size();
    if(len == 1) return 1;
    for(int c=1; c<=len/2; c++){
        int cnt = 0;
        for(int i=0; i<s.size()-c;){
            if(s.substr(i,c) != s.substr(i+c,c)){
                i+=c;
                continue;
            }
            int tmp = 0;
            while(s.substr(i,c) == s.substr(i+c,c)){
                tmp++;
                i += c;
            }
            cnt += tmp*c;
            tmp++;
            while(tmp){
                cnt--;
                tmp /= 10;
            }
        }
        cnt = len - cnt;
        if(answer > cnt) answer = cnt;
    }
    
    return answer;
}