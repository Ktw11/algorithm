#include <iostream>
#include <vector>

#define MAX 20001

using namespace std;
int flag = 1;
int value[MAX];
vector<int> graph[MAX];

int V,E,n1,n2;

bool dfs(int node, int f){
    value[node] = f;    

    for(int i=0; i<(graph[node].size()); i++){
        int next = graph[node][i];
        if(value[next] == 0 && !dfs(next, -f)){
            return false;
        }
        if(value[next] == f){
            return false;
        }
    }
    return true;
    
}

bool judge(){
    for(int i=0; i<V; i++){
        if(value[i]==0 && !dfs(i,1)){
            return false;
        }
    }
    return true;
}

int main() {
    int K;
    cin >> K;

    for(int i=0; i<K ;i++){
        for(int i=0; i<=V; i++){
            graph[i].clear();
            value[i] = 0;
        }

        cin >> V >> E;

        for(int j=0; j<E; j++){
            cin >> n1 >> n2;
            graph[n1].push_back(n2);
            graph[n2].push_back(n1);
        }
        
        if(V==1){
            cout << "NO" <<endl;
        }else if(judge() == true){
            cout << "YES" <<endl;
        }else{
            cout << "NO" <<endl;
        }

        
    }



    return 0;
}