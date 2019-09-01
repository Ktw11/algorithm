#include <stdio.h>
#define mod 1000000000

int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    long long dp[210][210] ={};

    for (int i=1; i<=n; i++)
        dp[i][1] = 1;
    
    for (int i=1; i<=k; i++)
        dp[1][i] = i;
 
    for (int i = 2; i <= n; i++){
        for (int j = 2; j <= k; j++){
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] % mod;
        }
    }
 
    printf("%lld\n", dp[n][k]%mod);

    return 0;
}


