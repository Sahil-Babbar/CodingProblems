

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
class HBpair{
    public:
        int height;
        bool balanced;
};
HBpair isBalancedTree(node*root){
    if(!root){
        HBpair ans;
        ans.height=0;
        ans.balanced=true;
        return ans;
    }

    // recursive case
    HBpair left=isBalancedTree(root->left);
    HBpair right=isBalancedTree(root->right);

    HBpair ans;
    // height calculate
    ans.height=max(left.height,right.height)+1;

    // check balanced or not

    if(abs(left.height-right.height)<=1 & left.balanced &right.balanced){
        ans.balanced=true;
    }
    else{
        ans.balanced=false;
    }
    return ans;
}
int main() {
    node* root =createTree();
    HBpair ans=isBalancedTree(root);
    if(ans.height){
        cout<<"Balanced";
    }
    else{
        cout<<"Not Balanced";
    }
}
