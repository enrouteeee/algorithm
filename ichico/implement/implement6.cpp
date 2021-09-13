//기둥과 보 설치 https://programmers.co.kr/learn/courses/30/lessons/60061
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

    bool bo[105][105]{}, gi[105][105]{};
    for (auto &it : build_frame) {
        int x = it[0], y = it[1], a = it[2], b = it[3];
        ++x;
        if (b == 1) { // 설치
            if (a == 0) { // 기둥
                if (y == 0 || bo[x - 1][y] || bo[x][y] ||
                    gi[x][y - 1]) gi[x][y] = 1;
            }
            else { // 보
                if (gi[x][y - 1] || gi[x + 1][y - 1] ||
                    bo[x - 1][y] && bo[x + 1][y]) bo[x][y] = 1;
            }
        }
        else { // 삭제
            if (a == 0) { // 기둥
                // 위의 기둥이 붕 뜨지는 않는가?
                // 위의 보가 양옆에 보가 있거나 한쪽 끝에 기둥이 있는가?
                bool flg = 1;
                if (gi[x][y + 1] && !bo[x][y + 1] && !bo[x - 1][y + 1]) flg = 0;
                if (bo[x][y + 1]) { // 오른쪽에 보가 있다
                    if (bo[x + 1][y + 1] && bo[x - 1][y + 1]); // 양옆에 보가 있으면 통과
                    else if (gi[x + 1][y]); // 기둥 있으면 통과
                    else flg = 0;
                }
                if (bo[x - 1][y + 1]) { // 왼쪽에 보가 있다
                    if (x - 2 >= 0 && bo[x - 2][y + 1] && bo[x][y + 1]);
                    else if (gi[x - 1][y]);
                    else flg = 0;
                }

                if (flg) gi[x][y] = 0;
            }
            else { // 보
                // 위의 기둥이 붕 뜨지는 않는가?
                // 양옆의 보가 각 끝에 기둥이 있는가?
                bool flg = 1;
                if (gi[x][y]) { // 왼쪽에 기둥이 있다
                    if (bo[x - 1][y]); // 왼쪽에 보가 있으면 통과
                    else if (gi[x][y - 1]); // 아래에 기둥이 있으면 통과
                    else flg = 0;
                }
                if (gi[x + 1][y]) { // 오른쪽에 기둥이 있다
                    if (bo[x + 1][y]); // 오른쪽에 보가 있으면 통과
                    else if (gi[x + 1][y - 1]); // 아래에 기둥이 있으면 통과
                    else flg = 0;
                }
                if (bo[x - 1][y]) { // 왼쪽에 보가 있다
                    if (gi[x - 1][y - 1] || gi[x][y - 1]); // 아래에 기둥이 있다
                    else flg = 0;
                }
                if (bo[x + 1][y]) { // 오른쪽에 보가 있다
                    if (gi[x + 1][y - 1] || gi[x + 2][y - 1]);
                    else flg = 0;
                }

                if (flg) bo[x][y] = 0;
            }
        }
    }

    for (int i = 1; i < 105; ++i) {
        for (int j = 0; j < 105; ++j) {
            if (gi[i][j]) answer.push_back({ i - 1, j, 0 });
            if (bo[i][j]) answer.push_back({ i - 1, j, 1 });
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}
