#include <stdio.h>

long long int dp[91][3];
long long int result = 0;

int main() {
    int n;
    scanf("%d",&n);
    
    dp[1][1] = 1;
    dp[1][2] = 0;
    dp[2][1] = 1;
    dp[2][2] = 0;
    

    for(int i=3;i<=n;i++) {
        dp[i][2] = dp[i-1][1] + dp[i-1][2];
        dp[i][1] = dp[i-1][2];
    }

    result = dp[n][1] + dp[n][2]*2;

    printf("%lld\n",result);

    return 0;
}


