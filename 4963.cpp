#include <iostream>

using namespace std;

int map[51][51];
bool visited[51][51];
int move_x[8] = {0,1,1,1,0,-1,-1,-1};
int move_y[8] = {1,1,0,-1,-1,-1,0,1};
int w, h;
int island = 0;

void DFS(int x, int y){
    visited[x][y] = true;
    for(int i=0; i<8; i++){
        int nx = x + move_x[i];
        int ny = y + move_y[i];
        if(0<=nx && nx<h && 0<=ny && ny<w){
            if(!visited[nx][ny] && map[nx][ny]){
                DFS(nx,ny);
            }
        }
    }
}

int main() {    
    
    while(true) {
        cin >> w >> h;
        if(w==0 && h==0){
            return 0;
        }

        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                cin >> map[i][j];
            }
        }

        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                if(!visited[i][j] && map[i][j]){
                    DFS(i,j);
                    island++;
                }
            }
        }

        cout << island << endl;
        island = 0;
        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                map[i][j] = 0;
                visited[i][j] = 0;
            }
        }
    }

    
}