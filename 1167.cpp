#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

#define MAX 100001

int dist[MAX];
bool visited[MAX];
vector<pair<int,int> > tree[MAX];
queue<int> Q;


void BFS(int node){
    Q.push(node);
    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();
        visited[x] = true;
        for(int i=0; i<tree[x].size();i++){
            if(!visited[tree[x][i].first]){
                dist[tree[x][i].first] = dist[x] + tree[x][i].second;
                Q.push(tree[x][i].first);
            }
        }
    }
}

int main(){
    int V;
    int result=0;
    cin >> V;
    for(int i=1; i<=V; i++){
        int vert, num, dis;
        cin >> vert;
        while(true){
            cin >> num;
            if(num == -1){
                break;
            }
            cin >> dis;
            tree[vert].push_back(make_pair(num,dis));
        }
    }

    BFS(1);

    int max=0, max_index;
    for(int i=1; i<=V;i++){
        if(max < dist[i]){
            max_index = i;
            max = dist[i];
        }
        dist[i] = 0;
        visited[i] = false;
    }

    BFS(max_index);
    max = 0;
    max_index = 0;

    for(int i=0; i<=V; i++){
        if(max < dist[i]){
            max_index = i;
            max = dist[i];
        }
        dist[i] = 0;
        visited[i] = false;
    }
    cout << max << endl;
    return 0;
}