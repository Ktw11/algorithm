#include <stdio.h>

int max(int a, int b){
    return a >= b ? a : b;
}

int main() {
    int n;
    
    int og[302] = {};
    int dp[302] = {};

    scanf("%d",&n);
    
    for(int i = 1;i<=n;i++){
        scanf("%d",&og[i]);
    }
    dp[1] = og[1];
    dp[2] = dp[1] + og[2];
    for(int i=3;i<=n;i++){
        dp[i] = max(og[i]+og[i-1]+dp[i-3], og[i]+dp[i-2]);
    }

    printf("%d\n",dp[n]);

    return 0;
}


