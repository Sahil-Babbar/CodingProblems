

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
// Accepts the old root node and data and returns the new node;
node* insertinBST(node*root,int d){
    if(root==NULL){
        return new node(d);
    }
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
bool search(node*root,int data){
    if(root==NULL){
        return false;
    }
    else{
        return true;
    }
    if(root->data==data){
        return true;
    }
    if(data<=root->data){
        search(root->left,data);
    }
    else{
        search(root->right,data);
    }
}
int main() {
     node*root=build();
     cout<<search(root,6);
}
