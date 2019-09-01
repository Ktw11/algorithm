#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 1001;
int n,m,v;
bool visit[MAX];
int adj[MAX][MAX];
queue<int> Q;

void dfs(int x){
    cout << x << " ";

    for(int i=1; i<=n ;i++){
        if(adj[x][i] && !visit[i]){
            visit[i] = true;
            dfs(i); 
        }
    }
}

void bfs(int x){
    Q.push(x);
    visit[x] = true;

    while(!Q.empty()){
        x = Q.front();
        Q.pop();

        cout << x << " ";

        for(int i=1; i<=n ;i++){
            if(adj[x][i] && !visit[i]){
                visit[i] = true;
                Q.push(i);
            }

        }
    }
}

int main(){
    cin >> n >> m >> v;

    for(int i=0; i<m; i++){
        int from, to;
        cin >> from >> to;
        adj[from][to] = 1;
        adj[to][from] = 1;
    }
    
    visit[v] = 1;
    dfs(v);
    cout << endl;

    memset(visit, false, sizeof(visit));
    bfs(v);
    cout << endl;

    return 0;
}