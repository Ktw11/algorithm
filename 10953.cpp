#include <stdio.h>

int main(){
    int a,b,ans,n;
    scanf("%d",&n);

    for (int i=0;i<n;i++){
        scanf("%d,%d",&a,&b);
        ans = a + b;
        printf("%d\n",ans);
    }
    return 0;
}