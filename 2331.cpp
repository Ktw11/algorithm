#include <iostream>
#include <math.h>
#include <vector>

#define MAX 240000

using namespace std;

bool check[MAX];
vector<int> D;

int main() {
    int A, P, n;
    int count = 0;
    cin >> A >> P;
    D.push_back(A);

    while(!check[A]){
        int next = 0;
        check[A] = true;
        for(int i=A; i>0; i/=10){
            next += pow(i % 10,P);
        }
        D.push_back(next);
        A = next;
    }

    for(int i=0; i<D.size(); i++){
        if(D.at(i) == A){
            break;
        }
        count++;
    }
    
    cout << count << endl;

    return 0;
}