#include <stdio.h>

void Qsort(int arr[], int l, int r){
    int pivot = l;
    int j = l;
    int i = l+1;

    if(l < r){
        for(;i<=r;i++){
            if(arr[i]<arr[pivot]){
                j++;
                int tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
        }
        int tmp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = tmp;
        j = pivot;
        Qsort(arr, l, pivot-1);
        Qsort(arr, pivot+1, r);
    }
}

int main(){
    int n;
    int mat[1000001];
    scanf("%d",&n);    
    for(int i=0;i<n;i++){
        scanf("%d",&mat[i]);
    }

    Qsort(mat,0,n-1);
    
    for(int i=0;i<n;i++){
        printf("%d\n",mat[i]);
    }

    return 0;
}