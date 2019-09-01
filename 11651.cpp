#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001
using namespace std;

vector<pair<int,int> > dot;


int main() {
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        int x,y;
        cin >> x >> y;
        dot.push_back(make_pair(y,x));
    }
    sort(dot.begin(), dot.end());
    for(int i=0; i<N; i++){
        cout << dot[i].second << " " << dot[i].first << '\n';
    }
    

}