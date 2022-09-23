

#include <iostream>
using namespace std;
class node{
    public:
        int data;
        node*left;
        node*right;
        node(int d){
            data=d;
        }
};
node*createTree(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    node*root=new node(d);
    root->left=createTree();
    root->right=createTree();
    return root;

}
int height(node*root){
    if(!root){
        return 0;
    }
    
    int left_height=height(root->left);
    int right_height=height(root->right);
    return  max(left_height,right_height)+1;
}
int diameter(node*root){
    // base case
    if(root==NULL){
        return 0;
    }
    // recursive case
    int op1=height(root->left)+height(root->right);
    int op2=diameter(root->left);
    int op3=diameter(root->right);

    return max(op1,max(op2,op3));

}
class Pair{
    public:
        int height;
        int dia;
};
Pair fastDiameter(node*root){
    // base case
    if(!root){
        Pair ans;
        ans.height=ans.dia=0;
        return ans;
    }
    // recursive case
   Pair left= fastDiameter(root->left);
   Pair right=fastDiameter(root->right);

   Pair ans;
//    Calculating the height
    ans.height=max(left.height,right.height)+1;
//     Calculating the diameter
    int op1=left.height+right.height;
    int op2=left.dia;
    int op3=right.dia;
    ans.dia=max(op1,max(op2,op3));
    return ans;
}

int main() {
   node*root=createTree();
   cout<<"Diameter  "<<diameter(root);
   Pair ans=fastDiameter(root);
   cout <<"\n"<<ans.dia;
}
