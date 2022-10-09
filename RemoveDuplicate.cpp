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
void removeDuplicates(node* head){
    unordered_set<int> visited;  //hash to store the visited values
    node* prev=NULL;
    node* curr=head;
    while(curr!=NULL){
        // if current value is already visited
        if(visited.find(curr->data)!=visited.end()){
            prev->next=curr->next;
            delete curr;
            curr=prev->next;
        }
        else{
            visited.insert(curr->data);
            prev=curr;
            curr=curr->next;
        }
    }
}
void printL(node*head){
    while(head!=NULL){
        cout<<head->data<<"-->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}
int main() {
    node *head,*tail;
    head =tail=NULL;

    InsertatEnd(head,tail,4);
    InsertatEnd(head,tail,5);
    InsertatEnd(head,tail,3);
    InsertatEnd(head,tail,3);
    removeDuplicates(head);
    printL(head);
}
