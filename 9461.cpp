#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        int m;
        scanf("%d",&m);
        long long dp[102] = {};

        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 1;
        dp[4] = 2;
        for(int i=5;i<=m;i++){
            dp[i] = dp[i-1] + dp[i-5];
        }
        printf("%lld\n",dp[m]);
    }

    return 0;
}