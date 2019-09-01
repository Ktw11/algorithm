#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

int e;
vector<int> node[MAX];
bool visited[MAX];
int parent[MAX];

void DFS(int n){
    visited[n] = true;
    for(int i=0; i<node[n].size(); i++){
        if(!visited[node[n][i]]){
            parent[node[n][i]] = n;
            DFS(node[n][i]);
        }
    }
}

int main(){
    int N;
    int v,p;
    cin >> N;

    for(int i=1; i<N; i++){
        cin >> v >> p;
        node[v].push_back(p);
        node[p].push_back(v);
    }

    DFS(1);

    for(int i=2; i<=N; i++){
        cout << parent[i] << '\n';
    }

    return 0;
}