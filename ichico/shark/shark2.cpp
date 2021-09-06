//청소년 상어
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct space{
    int h;
    int x;
    int y;
    int d;
}space;

space s[17];
space z;

int board[4][4];

int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int max;
int result;

void move();

void init(){
    int tmp = board[0][0];
    s[tmp].h = 0;
    z.h = 1;
    z.x = s[tmp].x;
    z.y = s[tmp].y;
    z.d = s[tmp].d;
    board[0][0] = -1;
    
    move();
    result = tmp;
    max = result;
}

void move(){
    for(int i=1; i<=16; i++){
        if(s[i].h == 0) continue;
        
        int nx, ny;
        nx = s[i].x + dx[s[i].d];
        ny = s[i].y + dy[s[i].d];
        
        int flag = 0;
        for(int d=0; d<8; d++){
            if(nx < 4 && nx >= 0 && ny < 4 && ny >= 0 && board[ny][nx] != -1) {
                flag = 1;
                break;
            }
            s[i].d = (s[i].d+1) % 8;
            nx = s[i].x + dx[s[i].d];
            ny = s[i].y + dy[s[i].d];
        }
        if(flag == 0) continue;
        if(board[ny][nx] ==0){
            board[ny][nx] = i;
            board[s[i].y][s[i].x] = 0;
            s[i].x = nx;
            s[i].y = ny;
            
            continue;
        }
        
        int tmp_n = board[ny][nx];
        board[ny][nx] = i;
        board[s[i].y][s[i].x] = tmp_n;
        
        space tmp_s;
        tmp_s.x = s[tmp_n].x;
        tmp_s.y = s[tmp_n].y;
        s[tmp_n].x = s[i].x;
        s[tmp_n].y = s[i].y;
        s[i].x = tmp_s.x;
        s[i].y = tmp_s.y;
    }
}

void solve(){
    
    int nx, ny;
    nx = z.x + dx[z.d];
    ny = z.y + dy[z.d];
    
    while(1){
        if(nx < 0 || nx >= 4 || ny < 0 || ny >= 4) break;
        if(board[ny][nx] == 0){
            nx += dx[z.d];
            ny += dy[z.d];
            continue;
        }
        //backup
        space oz;
        memcpy(&oz, &z, sizeof(space));
        int board_[4][4];
        for(int i=0;i<4;i++){
            for(int j=0; j<4;j++){
                board_[i][j] = board[i][j];
            }
        }
        space s_[17];
        memcpy(&s_, &s, sizeof(space)*17);
        //
        int tmp_n = board[ny][nx];
        board[z.y][z.x] = 0;
        board[ny][nx] = -1;
        z.y = ny;
        z.x = nx;
        z.d = s[tmp_n].d;
        s[tmp_n].h = 0;
        result += tmp_n;
        if(max < result) max = result;
        
        move();
        solve();
        
        //
        result -= tmp_n;
        memcpy(&z, &oz, sizeof(space));
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                board[i][j] = board_[i][j];
            }
        }
        memcpy(&s, &s_, sizeof(space)*17);
        
        nx = nx + dx[z.d];
        ny = ny + dy[z.d];
    }
}

int main(int argc, const char * argv[]) {
    
    for(int i=0;i<4;i++){
        for(int j=0; j<4; j++){
            int a, b;
            scanf("%d %d", &a, &b);
            board[i][j] = a;
            s[a].h = 1;
            s[a].y = i;
            s[a].x = j;
            s[a].d = b-1;
        }
    }
    
    init();
    solve();
    
    printf("%d", max);
    
    return 0;
}

