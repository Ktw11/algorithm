#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;



bool cmp(pair<int,string> a, pair<int,string> b){
    return a.first < b.first;
}

int main(){
    int N;
    cin >> N;
    vector<pair<int,string> > user(N);
    for(int i=0; i<N; i++){
        cin >> user[i].first >> user[i].second;
    }

    stable_sort(user.begin(),user.end(),cmp);

    for(int i=0; i<N; i++){
        cout << user[i].first << " " << user[i].second << '\n';
    }



    return 0;
}