#include <stdio.h>

int dp[1001];

int main() {
    int n,tmp;
    scanf("%d",&n);
    dp[2] = 2;
    dp[1] = 1;
    dp[0] = 1;

    for(int j=0;j<n;j++){
        scanf("%d",&tmp);
        for(int i=3;i<=tmp;i++) {
        dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
        }    
        printf("%d\n",dp[tmp]);
    }
    return 0;
}