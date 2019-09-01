#include <stdio.h>

int max(int a, int b, int c){
    int tmp;
    if(a < b){
        return b > c ? b : c;
    }else{
        return a > c ? a : c;
    }
}


int main() {
    int n,m,result;
    int og[10001];
    int dp[10001];

    scanf("%d",&n);
    
    for(int i = 1;i<=n;i++){
        scanf("%d",&m);
        og[i] = m;
    }
    dp[0] = 0;
    dp[1] = og[1];
    dp[2] = dp[1] + og[2];


    for(int j=3;j<=n;j++){
        dp[j] = max(dp[j-2]+og[j], dp[j-3]+og[j-1]+og[j],dp[j-1]);
    }
    printf("%d\n",dp[n]);

    return 0;
}


