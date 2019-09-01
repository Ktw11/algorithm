#include <iostream>
using namespace std;

int main(){
    int a,b,ans;

    while(cin >> a >> b){
        if(a==0 && b==0){
            break;
        }
        ans = a + b;
        cout << ans << endl;
    }
    return 0;
}