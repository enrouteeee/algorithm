//카드 정렬하기
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, result;
priority_queue<int> pq;

int main(void) {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(-x);
    }

    while (pq.size() != 1) {
        int one = -pq.top();
        pq.pop();
        int two = -pq.top();
        pq.pop();
        int summary = one + two;
        result += summary;
        pq.push(-summary);
    }

    cout << result << '\n';
}