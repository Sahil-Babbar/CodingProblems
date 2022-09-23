

#include <iostream>
using namespace std;
class node{
    public:
        int data;
        node*left;
        node*right;
        node(int d){
            data=d;
            left=NULL;
            right=NULL;
        }
};
// Accepts the old root node and data and returns the new node..
node* insertinBST(node*root,int d){
    if(root==NULL){
        return new node(d);

    }
    // Recursive case -insert in bst and update the pointers...
    if(d<=root->data){
        root->left=insertinBST(root->left,d);
    }
    else{
        root->right=insertinBST(root->right,d);
    }
    return root;
}
node* build(){
    // Read a list of numbers till -1 and also these numbers are inserted in BST
    int d;
    cin>>d;
    node*root=NULL;
    while(d!=-1){
        root=insertinBST(root,d);
        cin>>d;
    }
    return root;
}
void inorder(node*root){
    if(!root){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main() {
    node*root=build();
    inorder(root);
    
}
