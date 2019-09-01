#include <stdio.h>

int max(int a, int b){
    return a >= b ? a : b;
}

int main() {
    int n;
    
    int og[100001] = {};
    int dp[100001] = {};

    scanf("%d",&n);
    
    for(int i = 1;i<=n;i++){
        scanf("%d",&og[i]);
    }
    int result = og[1];
    for(int i=1;i<=n;i++){
        dp[i] = max(og[i], og[i]+dp[i-1]);
        if(result<dp[i]){
            result = dp[i];
        }
    }

    printf("%d\n",result);

    return 0;
}


