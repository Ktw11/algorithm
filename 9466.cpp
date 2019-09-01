#include <iostream>
#include <vector>

#define MAX 100001
using namespace std;

int visited[MAX], G[MAX];
bool finished[MAX];

int cnt = 0;

void DFS(int node){
    if(finished[node] == true || visited[node] == -1) {
        return;
    }
    if(visited[node] == 0){
        visited[node] = 1;
    }else if(visited[node] == 1){
        finished[node] = true;
        cnt++;
    }
    DFS(G[node]);
    visited[node] = -1;
}

int main(){
    int T;
    cin >> T;
    while(T--) {
        int n, choose;
        cin >> n;
        for(int i=1; i<=n;i++){
            cin >> G[i];
        }
        for(int i=1; i<=n; i++){
            if(visited[i]==0){
                DFS(i);
            }
        }

        if(n == 1){
            cout << 0 << endl;
        }
        else{
            cout << n - cnt <<endl;
        }
        cnt = 0;

        for(int i=0; i<=n;i++){
            visited[i] = 0;
            finished[i] = 0;
            G[i] = 0;
        }
    }
    


    return 0;
}