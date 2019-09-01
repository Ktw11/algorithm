#include <iostream>
#include <vector>

#define MAX 10001

using namespace std;

int distance1[MAX];
bool visited[MAX];
vector<pair<int,int> > adj[MAX];

void DFS(int node){
    visited[node] = true;
    for(int i=0;i<adj[node].size(); i++){
        int cur = adj[node][i].first;
        if(!visited[cur]){
            distance1[cur] = distance1[node] + adj[node][i].second;
            DFS(cur);
        }
    }

}

int main(){
    int V,tmp;
    cin >> V;
    tmp = V;
    for(int i=1; i<V; i++){
        int parent,child,dist;
        cin >> parent >> child >> dist;
        adj[parent].push_back(make_pair(child,dist));
        adj[child].push_back(make_pair(parent,dist));
    }

    DFS(1);

    int idx_max = 0;
    int idx;
    for(int i=1; i<=V; i++){
        if(distance1[i] > idx_max){
            idx = i;
            idx_max = distance1[i];
        }    
    }

    for(int i=1; i<=V; i++){
        distance1[i] = 0;
        visited[i] = false;
    }

    DFS(idx);

    idx_max = 0;
    for(int i=1; i<=V; i++){
        if(distance1[i] > idx_max){
            idx_max = distance1[i];
        }    
    }

    cout << idx_max << endl;
    return 0;
}