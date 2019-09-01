#include <stdio.h>

int main() {
    int n,m;
    int result = 0;
    int og[1003] = {};
    int dp[1003] = {};
    int dp2[1003] = {};

    scanf("%d",&n);
    
    for(int i = 1;i<=n;i++){
        scanf("%d",&m);
        og[i] = m;
    }
    
    for(int j=1;j<=n;j++){
        int tmp = 0;
        for(int k=0;k<j;k++){
            if(og[j]>og[k]){
                if(tmp < dp[k]){
                    tmp = dp[k];
                }
            }
        }
        dp[j] = tmp + 1;
    }
    for(int j=n;j>=1;j--){
        int tmp = 0;
        for(int k=n+1;k>j;k--){
            if(og[j]>og[k]){
                if(tmp < dp2[k]){
                    tmp = dp2[k];
                }
            }
        }
        dp2[j] = tmp + 1;
    }

    for(int j=1;j<=n;j++){
        if(result < dp[j] + dp2[j]){
            result = dp[j] + dp2[j];
        }
    }

    printf("%d\n",result-1);

    return 0;
}


