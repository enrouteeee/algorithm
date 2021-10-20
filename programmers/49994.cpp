#include <string>
#include <map>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int board[11][11];

int solution(string dirs) {
    int answer = 0;
    
    map<pair<pair<int,int>,pair<int,int>>,int> m;
    
    int x = 5;
    int y = 5;
    for(int i=0; i<dirs.size(); i++){
        int nx = x;
        int ny = y;
        if(dirs[i] == 'U'){
            nx += dx[3];
            ny += dy[3];
        }
        else if(dirs[i] == 'L'){
            nx += dx[1];
            ny += dy[1];
        }
        else if(dirs[i] == 'R'){
            nx += dx[0];
            ny += dy[0];
        }
        else if(dirs[i] == 'D'){
            nx += dx[2];
            ny += dy[2];
        }
        
        if(nx < 0 || ny < 0 || nx >= 11 || ny >= 11)
            continue;
        
        int a, b, c, d;
        if(x > nx){
            a = x;
            b = nx;
        }
        else{
            a = nx;
            b = x;
        }
        if(y > ny){
            c = y;
            d = ny;
        }
        else{
            c = ny;
            d = y;
        }
        m[{{a,b},{c,d}}]++;
        x = nx;
        y = ny;
    }
    
    answer = m.size();
    
    return answer;
}