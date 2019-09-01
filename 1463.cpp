#include <stdio.h>

int dp[1000001];

int f_min(int a, int b) {
    if(a > b){
        return b;
    }else{
        return a;
    }
}

int main() {
    int n;
    scanf("%d",&n);
    dp[1] = 0;
    for(int i=2;i<=n;i++) {
        dp[i] = dp[i-1] + 1;
        if(i%2==0){
            dp[i] = f_min(dp[i],dp[i/2] + 1);
        }
        if(i%3==0){
            dp[i] = f_min(dp[i],dp[i/3] + 1);
        }
    }    
    printf("%d\n",dp[n]);
    return 0;
}