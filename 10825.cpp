#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct score{
    string name;
    int kr;
    int eg;
    int mat;
};

bool cmp(struct score a, struct score b){
    if(a.kr==b.kr && a.eg==b.eg && a.mat==b.mat){
        return a.name < b.name;
    }else if(a.kr==b.kr && a.eg==b.eg){
        return a.mat > b.mat;
    }else if(a.kr==b.kr){
        return a.eg < b.eg;
    }else{
        return a.kr > b.kr;
    }
}


int main(){
    int N;
    cin >> N;
    vector<score> stud(N);

    for(int i=0; i<N; i++){
        cin >> stud[i].name >> stud[i].kr >> stud[i].eg >> stud[i].mat;
    }

    sort(stud.begin(), stud.end(), cmp);

    for(int i=0; i<N; i++){
        cout << stud[i].name << '\n';
    }
    
    return 0;
}