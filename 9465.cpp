#include <stdio.h>

int max(int a, int b){
    return a > b ? a : b;
}


int main() {
    int n,m,tmp;
    scanf("%d",&n);
    
    for(int i = 0;i<n;i++){
        scanf("%d",&m);

        int dp[2][100001];
        int og[2][100001];

        for(int j=0;j<2;j++){
            for(int k=1;k<=m;k++){
                scanf("%d",&og[j][k]);
            }
        }
        dp[0][0] = dp[1][0] = 0;
        dp[0][1] = og[0][1];
        dp[1][1] = og[1][1];


        for(int l=2;l<=m;l++){
            dp[0][l] = max(dp[1][l-1],dp[1][l-2]) + og[0][l];
            dp[1][l] = max(dp[0][l-1],dp[0][l-2]) + og[1][l];
        }

        printf("%d\n",max(dp[0][m],dp[1][m]));
    }

    return 0;
}


