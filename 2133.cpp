#include <stdio.h>
#include <math.h>

int main() {
    int n;
    scanf("%d",&n);

    int dp[32] = {};

    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;
    
    for(int i=3;i<=n;i++){
        if(i%2 == 0){
            dp[i] = dp[i-2] * 3;
            for(int j=4; j<=i; j+=2){
                dp[i] += dp[i-j] * 2;
            }
        }
        else{
            dp[i] = 0;
        }
    }

    printf("%d\n",dp[n]);

    return 0;
}


