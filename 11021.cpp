#include <iostream>
using namespace std;

int main(){
    int n,a,b,ans;
    cin >> n;

    for (int i=0;i<n;i++){
        cin >> a >> b;
        ans = a + b;
        cout << "Case #" << i+1 << ": " << ans << endl;
    }
    return 0;
}