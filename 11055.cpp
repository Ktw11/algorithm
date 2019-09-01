#include <stdio.h>

int main() {
    int n,m;
    int result = 0;
    int og[1002];
    int dp[1002];

    scanf("%d",&n);
    
    for(int i = 1;i<=n;i++){
        scanf("%d",&m);
        og[i] = m;
    }
    dp[0] = 0;
    for(int j=1;j<=n;j++){
        int tmp = 0;
        for(int k=0;k<j;k++){
            if(og[j]>og[k]){
                if(tmp < dp[k]){
                    tmp = dp[k];
                }
            }
        }
        dp[j] = tmp + og[j];
        if(dp[j]>result) {
            result = dp[j];
        }
    }
    printf("%d\n",result);

    return 0;
}


