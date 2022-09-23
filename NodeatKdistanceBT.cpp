

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
node* createTree(){
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
void printatlevelK(node*root,int k){
    if(root==NULL){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    printatlevelK(root->left,k-1);
    printatlevelK(root->right,k-1);
    return;
}
int printatDistancek(node*root,node*target,int k){
    if(root==NULL){
        return -1;
    }
    if(root==target){
        printatlevelK(target,k);
        return 0;
    }

    // next step ancestor
    int dl=printatDistancek(root->left,target,k);
    if(dl!=-1){
        // Again there 2 cases
        // Ancestor itself or need to go to rightsubtree
        if(dl+1==k){
            cout<<root->data<<" ";
        }
        else{
            printatlevelK(root->right,k-2-dl);
        }
        return 1+dl;87
    }
    int dr=printatDistancek(root->right,target,k);
    if(dr!=-1){
        // Again there 2 cases
        // Ancestor itself or need to go to leftsubtree
        if(dr+1==k){
            cout<<root->data<<" ";
        }
        else{
            printatlevelK(root->left,k-2-dr);
        }
        return 1+dr;
    }
    return -1;
}
void print(node*root){
    // base case
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}
int main() {
   node*root= createTree();
   print(root);
   node*target=root->left;
   printf("\n");
   printatDistancek(root,target,2);
}
