#include<iostream>
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
void insertatEnd(node*&head,node*&tail,int data){
    node*n=new node(data);
    if(!head){
        head=n;
        tail=n;
    }
    else{
        tail->next=n;
        tail=n;
    }
}
void reverseLL(node*&head,node*&tail){
    node*c=head;
    node*p=NULL;
    node*n;
    while (c!=NULL)
    {
        n=c->next;
        c->next=p;
        p=c;
        c=n;
    }
    swap(head,tail);
    
}
void display(node*head){
    while(head!=NULL){
        cout<<head->data<<"-->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
    node*head=NULL;
    node*tail=NULL;
    insertatEnd(head,tail,1);
    insertatEnd(head,tail,2);
    insertatEnd(head,tail,3);
    insertatEnd(head,tail,4);
    insertatEnd(head,tail,5);
    insertatEnd(head,tail,6);

    cout<<"Original link list..."<<endl;
    display(head);
    reverseLL(head,tail);
    cout<<"Reversed linklist.."<<endl;
    display(head);
}