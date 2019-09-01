#include <iostream>
#include <vector>

#define MAX 100001

using namespace std;

int max_dist[MAX][MAX];
bool visited[MAX];
vector<pair<int,int> > tree[MAX];
int tmp = 0;

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

    cout << result << endl;

    return 0;
}