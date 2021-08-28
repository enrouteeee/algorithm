//안테나
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
    int N;
    cin >> N;

    vector<int> num;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        num.push_back(a);
    }

    sort(num.begin(), num.end());

    cout << num[(N - 1) / 2] << '\n';
}