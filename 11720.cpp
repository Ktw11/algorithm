#include <stdio.h>

int main() {
    int n,tmp;
    int result = 0;
    int str[100];
    scanf("%d\n",&n);
    for (int i=0;i<n;i++){
        scanf("%1d",&tmp);
        str[i] = tmp;
        result += str[i];
    }

    printf("%d\n",result);
    return 0;
}