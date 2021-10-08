#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int maxx = 0;
    int maxy = 0;
    for(int i=0; i<sizes.size(); i++){
        int tmp = 0;
        if(sizes[i][0] < sizes[i][1]){
            tmp = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = tmp;
        }
        if(maxx < sizes[i][0])
            maxx = sizes[i][0];
        if(maxy < sizes[i][1])
            maxy = sizes[i][1];
    }
    
    return maxx*maxy;
}