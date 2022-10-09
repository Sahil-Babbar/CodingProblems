#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        node*next;
        node(int d){
            data=d;
            next=NULL;
        }
};
void InsertatEnd(node*&head,node*&tail,int d){
    node*n=new node(d);
    if(!head){
        n->next=NULL;
        head=tail=n;

    }
    else{
        tail->next=n;
        tail=n;
    }
}
void printL(node*head){
    while(head!=NULL){
        cout<<head->data<<"-->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}
node* removeAllDuplicates(node*&head){
    map<int,int> visited;
    // node* prev=NULL;
    node* curr=head;
    while(curr!=NULL){
        if(visited.find(curr->data)!=visited.end()){
            visited.erase(curr->data);
        }
        else{
            visited.insert({curr->data,1});
        }
        curr=curr->next;
    }

//     int count=0;
//     node*nh=NULL;
//     node*nt=NULL;
//     for(auto i :visited){
//         node* n=new node(i.first);
//         if(count==0){
//             nh=n;
//             nt=n;
//             count++;
//         }
//         else{
//             nt->next=n;
//             nt=n;
//         }
//     }
    
//   return nh;  
}
int main(){
    node*head=NULL;
    node*tail=NULL;
    InsertatEnd(head,tail,1);
    InsertatEnd(head,tail,1);
    InsertatEnd(head,tail,3);
    InsertatEnd(head,tail,4);
    printL(head);
    node*nh=removeAllDuplicates(head);
    printL(nh);
}