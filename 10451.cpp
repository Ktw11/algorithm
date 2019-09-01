#include <iostream>
#include <vector>

using namespace std;

bool visited[1002];
vector<int> G[1002];

void DFS(int node) {
    visited[node] = true;

    for(int i=0; i<G[node].size(); i++){
        int next = G[node][i];
        if(!visited[next]){
            DFS(next);
        }
    }
}

int main() {
    int count = 0;
    int T;
    cin >> T;
    
    while(T--){
        int N,p;
        cin >> N;
        for(int i=1; i<=N;i++){
            cin >> p;
            G[i].push_back(p);
        }

        for(int i=1; i<=N;i++){
            if(!visited[i]){
                DFS(i);
                count++;
            }
        }

        cout << count << endl;
        count = 0;

        for(int i=1; i<=N; i++){
            G[i].clear();
            visited[i] = 0;
        }
    }

    return 0;
}