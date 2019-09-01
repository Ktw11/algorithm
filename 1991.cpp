#include <iostream>

using namespace std;

struct node{
    int val;
    node* L;
    node* R;
};
struct node tree[28];

void prefix(node root){
    cout << (char)(root.val+'A');
    if(root.L!=NULL){
        prefix(*root.L);
    }
    if(root.R!=NULL){
        prefix(*root.R);
    }
}

void inorder(node root){
    if(root.L!=NULL){
        inorder(*root.L);
    }
    cout << (char)(root.val+'A');
    if(root.R!=NULL){
        inorder(*root.R);
    }
}

void postfix(node root){
    if(root.L!=NULL){
        postfix(*root.L);
    }
    if(root.R!=NULL){
        postfix(*root.R);
    }
    cout << (char)(root.val+'A');
}


int main() {
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        tree[i].val = i;
    }
    for(int i=0; i<N; i++){
        char value, left, right;
        cin >> value >> left >> right;
        if(left != '.'){
            tree[value-'A'].L = &tree[(left-'A')];
        }
        if(right != '.'){
            tree[value-'A'].R = &tree[(right-'A')];
        }
    }
    prefix(tree[0]);
    cout << endl;
    inorder(tree[0]);
    cout << endl;
    postfix(tree[0]);
    cout << endl;



    return 0;
}