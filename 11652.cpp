#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int nc;
    long long card[1000000];
    cin >> nc;

    for(int i=0; i<nc; i++){
        cin >> card[i];
    }
    sort(card,card+nc);

    long long result = card[0];
    int tcnt = 1;
    int fcnt = 1;

    for(int i=0;i<nc;i++){
        if(card[i] == card[i+1]){
            tcnt++;
        }else{
            tcnt = 1;
        }
        if(fcnt < tcnt){
            fcnt = tcnt;
            result = card[i];
        }
    }

    cout << result << endl;

    return 0;
}