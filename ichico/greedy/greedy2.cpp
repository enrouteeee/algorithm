//곱하기 혹은 더하기
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    
    cin >> s;
    
    int ans = 0;
    for(int i=0; i<s.size(); i++){
        int num = s[i] -'0';
        if(num == 0){
            continue;
        }
        else{
            if(ans == 0)
                ans += num;
            else
                ans *= num;
        }
    }
    
    cout << ans;

    return 0;
}
