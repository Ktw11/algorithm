#include <stdio.h>

int main() {
    int n,m;
    int result = 0;
    int og[1001];
    int dp[1001];

    scanf("%d",&n);
    
    for(int i = 1;i<=n;i++){
        scanf("%d",&m);
        og[i] = m;
    }

    for(int j=1;j<=n;j++){
        int min = 0;
        for(int k=0;k<j;k++){
            if(og[j]>og[k]){
                if(min < dp[k]){
                    min = dp[k];
                }
            }
        }
        dp[j] = min + 1;
        if(dp[j]>result) {
            result = dp[j];
        }
    }
    printf("%d\n",result);

    return 0;
}


