#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int N, K;
    scanf("%d %d",&N,&K);
    long long arg[N+1];

    for(int i=0; i<N; i++){
        scanf("%lld",&arg[i]);
    }
    sort(arg,arg+N);

    printf("%lld\n",arg[K-1]);

    return 0;
}