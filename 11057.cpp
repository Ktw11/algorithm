#include <stdio.h>

int dp[1001][11];
int result = 0;

int main() {
    int n;
    scanf("%d",&n);
    
    for(int i=0;i<10;i++) {
        dp[1][i] = 1;
    }

    for(int i=2;i<=n;i++) {
        for(int j=0;j<10;j++){
           for(int k=j;k<10;k++){
               dp[i][j] = (dp[i][j] + dp[i-1][k])%10007;
           }
        }
    }

    for(int k=0;k<10;k++){
        result = (result+dp[n][k]) % 10007;
    }

    printf("%d\n",result%10007);

    return 0;
}


