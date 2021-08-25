//모험가 길드
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int N;
    vector<int> arr;
    
    cin >> N;
    
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }
    
    sort(arr.begin(), arr.end());
    
    int ans=0;
    int cnt = 0;
    for(int i=0; i<N; i++){
        cnt++;
        if(cnt >= arr[i]){
            cnt = 0;
            ans++;
        }
    }
    
    cout << ans;

    return 0;
}
