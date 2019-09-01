#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int N, tmp;
    int num[10001] = {0,};

    scanf("%d",&N);

    for(int i=0;i<N;i++){
        scanf("%d",&tmp);
        num[tmp]++;
    }

    for(int i=1;i<=10000;i++){
        if(num[i]==0){
            continue;
        }
        for(int j=0; j<num[i]; j++){
            printf("%d\n",i);
        }
    }

    return 0;
}
