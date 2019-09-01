#include <iostream>
#include <queue>

#define MAX 1001

using namespace std;


int box[MAX][MAX];
int M,N;
int ans = 0;
int move_x[4] = {0,0,-1,1};
int move_y[4] = {-1,1,0,0};
queue<pair<int,int> > Q;


void BFS(){
    while(!Q.empty()){
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + move_x[i];
            int ny = y + move_y[i];
            if(0<=nx && nx<N && 0<=ny && ny<M){
                if(box[nx][ny] == 0){
                    box[nx][ny] = box[x][y] + 1;     
                    Q.push(make_pair(nx,ny));
                }
            }
        }

    }
    
    return;
}


int main() {
    cin >> M >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> box[i][j];   
            if(box[i][j] == 1){
                Q.push(make_pair(i,j));
            }
        }
        
    }

    BFS();

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(box[i][j] == 0){
                cout << "-1" << endl;
                return 0;
            }
            if(ans < box[i][j]){
                ans = box[i][j];
            }
        }
        
    }

    cout << ans-1 << endl;

    return 0;
}