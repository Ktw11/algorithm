#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define mod 1000000

int main() {

    char og[5010] = {};
    scanf("%s",og+1);
    long long dp[5010] = {};
    dp[0] = 1;
    int x = (og[1]-'0') + (og[0]-'0') * 10;
    if(10<=x && x<=26){
        dp[1] = 2;
    }else{
        dp[1] = 1;
    }

    for(int i=2;i<strlen(og);i++){
        if(og[i] > '0'){
            dp[i] = (dp[i-1]) % mod;
        }
        int x = (og[i]-'0') + (og[i-1]-'0') * 10;
        if(10<=x && x<=26){
            dp[i] = (dp[i-2] + dp[i]) %mod;
        }
    }

    printf("%d\n", dp[strlen(og)-1]%mod);


    return 0;
}


