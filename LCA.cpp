

#include <iostream>
using namespace std;
class node{
    public:
        int data;
        node *left;
        node *right;
        node(int d){
            data=d;
            left=NULL;
            right=NULL;
        }
};
node*createTree(){
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    node*root=new node(data);
    root->left=createTree();
    root->right=createTree();
    return root;
}
node*lca(node*root,int a,int b){
    if(root==NULL){
        return NULL;
    }
    // when any one of the a and b is root then root is the lca
    if(root->data==a or root->data==b){
        return root;
    }

    // recursive case
    node*leftans=lca(root->left,a,b);
    node*rightans=lca(root->right,a,b);

    if(leftans!=NULL and rightans!=NULL){
        return root;
    }
    if(leftans!=NULL){
        return leftans;
    }
    return rightans;

}
int main() {
    node*root=createTree();
    int a=1,b=7;
    cout<<"lca of 1 and 7 is "<<lca(root,1,7)->data;
   
}
