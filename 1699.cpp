#include <stdio.h>

int main() {
    int n,min;
    scanf("%d",&n);

    int dp[1000002] = {};

    dp[0] = 0;
    
    for(int i=1;i<=n;i++){
        dp[i] = 10000000;
        for(int j=1;i-(j*j)>=0;j++){
            min = dp[i-(j*j)]+1;
            if(dp[i]>min){
                dp[i] = min;
            }
        }
    }

    printf("%d\n",dp[n]);

    return 0;
}


