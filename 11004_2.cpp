#include <iostream>

using namespace std;

int N, K;
int arr[5000001];

void swap(int array[], int a, int b){
    int tmp = array[a];
    array[a] = array[b];
    array[b] = tmp;
}

int partition(int array[], int left, int right){
    int pivot = array[left];
    int low = left;
    int high = right;

    while(low < high){
        while(pivot <= array[high]){
            high--;
        }
        while(low<high && pivot >= array[low]){
            low++;
        }
        swap(array, low, high);
    }
    swap(array,low,left);

    return low;
}

int quicksearch(int array[], int left, int right, int k){
    int pivot = partition(array, left, right);
    if(pivot == k){
        return array[pivot-1];
    }else if(pivot > k){
        quicksearch(array, left, pivot-1,k);
    }else{
        quicksearch(array, pivot+1, right,k);
    }
}

int main(){
    cin >> N >> K;

    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    // cout << quicksearch(arr,0,N-1,K-1) << endl;
    quicksearch(arr,0,N-1,K-1);
    cout << arr[K-1];

    return 0;
}