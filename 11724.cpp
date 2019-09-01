#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> G[1001];
bool visited[1001];

void dfs(int node){
    visited[node] = true;

    for(int i=0; i<G[node].size();i++){
        int con = G[node][i];
        if(!visited[con]){
            dfs(con);
        }
    }
}

int main() {
    cin >> N >> M;

    for(int i=0; i<M;i++){
        int n1, n2;
        cin >> n1 >> n2;

        G[n1].push_back(n2);
        G[n2].push_back(n1);
    }

    int cnt = 0;

    for(int i=1; i<=N; i++){
        if(!visited[i]){
            cnt++;
            dfs(i);
        }
    }

    cout << cnt << endl;

    return 0;
}