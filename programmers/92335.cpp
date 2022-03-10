#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

bool isPrime(long long n){
    if(n <= 1)
        return false;
    for(long long i=2; i<=sqrt(n); i++){
        if(n % i == 0)
            return false;
    }
    return true;
}

int solution(int n_, int k) {
    int answer = 0;

    long long cnt = 1;
    long long trans = 0;
    long long n = n_;
    while(n){
        int tmp = n % k;
        if(tmp == 0){
            if(isPrime(trans))
                answer++;
            cnt = 1;
            trans = 0;
            n /= k;
            continue;
        }
        trans += cnt*tmp;
        cnt *= 10;
        n /= k;
    }
    if(isPrime(trans)){
        answer++;
    }

    return answer;
}