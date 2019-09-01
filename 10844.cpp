#include <stdio.h>
#define e 1000000000

int main() {
    int dp[102][10];
    int n;
    int result = 0;
    scanf("%d",&n);


    for(int i=0;i<10;i++){
        dp[0][i] = 1;    
    }

    for(int j=1;j<n;j++){
        for(int h=0;h<10;h++){
            if(h==0){
                dp[j][h] = dp[j-1][h+1]%e;
            }
            else if(h==9){
                dp[j][h] = dp[j-1][h-1]%e;
            }
            else{
                dp[j][h] = (dp[j-1][h-1] + dp[j-1][h+1])%e;
            }
        }
    }
    
    for(int k=1;k<10;k++){
        result = (result + dp[n-1][k])%e;    
    }

    printf("%d\n",result%e);
    return 0;
}


/*
      1 2 3 4 5 6 7 8 9 
1:  1 1 1 1 1 1 1 1 1 1 
2:  1 2 2 2 2 2 2 2 2 1 
3:  2 3 4 4 4 4 4 4 3 2 
4:  3 6 7 8 8 8 8 7 6 3 
5:  
*/