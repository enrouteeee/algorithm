//볼링공 고르기
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N, M;
    int ball[11]={0,};
    
    cin >> N >> M;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        ball[a]++;
    }
    
    int ans=0;
    for(int i=1; i<=M; i++){
        //int cnt = 0;
        // for(int j=i+1; j<=M; j++){
        //     cnt += ball[j];
        // }
        N -= ball[i];
        //ans += ball[i] *cnt;
        ans += ball[i] * N;
    }
    
    cout << ans;

    return 0;
}
