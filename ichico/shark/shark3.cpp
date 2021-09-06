//어른 상어
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int N, M, k, M_;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

typedef struct shark{
    int x;
    int y;
    int d;
    int p[4][4];
    int h;
}shark;

typedef struct board{
    int smell;
    int time;
}board;

board b[20][20];
shark s[401];

void spend();
void move();

int main(){
    
    scanf("%d %d %d", &N, &M, &k);
    M_ = M;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int a;
            scanf("%d", &a);
            if(a == 0){
                b[i][j].smell = 0;
                b[i][j].time = 0;
            }
            else if(a != 0){
                b[i][j].smell = a;
                b[i][j].time = k;
                s[a].h = 1;
                s[a].x = j;
                s[a].y = i;
            }
        }
    }
    for(int i=1; i<=M; i++){
        int a;
        scanf("%d", &a);
        s[i].d = a-1;
    }
    for(int i=1; i<=M; i++){
        for(int j=0; j<4; j++){
            for(int k=0; k<4; k++){
                int a;
                scanf("%d", &a);
                s[i].p[j][k] = a-1;
            }
        }
    }
    int cnt = 0;
    while(1){
        move();
        cnt++;
        if(cnt > 1000 || M_ == 1)break;
    }
    
    if(cnt > 1000) printf("-1");
    else printf("%d", cnt);
    
    return 0;
}

void spend(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(b[i][j].time){
                b[i][j].time--;
                if(b[i][j].time == 0) b[i][j].smell = 0;
            }
        }
    }
}

void move(){
    for(int i=1; i<=M; i++){
        if(s[i].h == 0) continue;
        
        int flag_b =0;
        int blank[4] = {0,};
        int mysmell[4] = {0,};
        for(int d =0; d<4; d++){
            int nx = s[i].x + dx[d];
            int ny = s[i].y + dy[d];
            if(nx >= 0 && nx < N && ny >= 0 && ny < N && b[ny][nx].smell == 0) {
                blank[d] = 1;
                flag_b = 1;
            }
            else if(nx >= 0 && nx < N && ny >= 0 && ny < N && b[ny][nx].smell == i){
                mysmell[d] = 1;
            }
        }
        if(flag_b){
            for(int p=0; p<4; p++){
                if(blank[s[i].p[s[i].d][p]] == 1){
                    s[i].d = s[i].p[s[i].d][p];
                    s[i].x += dx[s[i].d];
                    s[i].y += dy[s[i].d];
                    break;
                }
            }
            continue;
        }
        for(int p=0; p<4; p++){
            if(mysmell[s[i].p[s[i].d][p]] == 1){
                s[i].d = s[i].p[s[i].d][p];
                s[i].x += dx[s[i].d];
                s[i].y += dy[s[i].d];
                break;
            }
        }
    }
    spend();
    for(int i=1; i<=M; i++){
        if(s[i].h == 0) continue;
        
        int x = s[i].x;
        int y = s[i].y;
        if(b[y][x].smell < i && b[y][x].time == k){
            s[i].h = 0;
            M_--;
            continue;
        }
        b[y][x].smell = i;
        b[y][x].time = k;
    }
}
