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
node*midelement(node*&head){
    if(!head || head->next==NULL){
        return head;
    }
    node*slow=head;
    node*fast=head->next;
    while(fast and fast->next){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
void reverse(node*&head,node*&tail){
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
bool checkPalindrome(node*head){
    node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    // calculate the middle element....
    node*mid=midelement(head);
    cout<<mid->data<<endl;

    // dividing the ll in 2 parts....
    node*a=head;
    node*b=mid->next;
    mid->next=NULL;
    reverse(b,temp); // reverse the 2nd half of the ll
    bool ispal=false;

    // traversing on 1st and 2nd half
    while(a and b){
        if(a->data==b->data){ // comparing data...
            ispal=true;
            a=a->next;
            b=b->next;
        }
        else{
            ispal=false;
            break;
        }

    }
    return ispal;
      
       
}
int main(){
    node*head=NULL;
    node*tail=NULL;
    InsertatEnd(head,tail,1);
    InsertatEnd(head,tail,2);
    InsertatEnd(head,tail,3);
    // InsertatEnd(head,tail,1);
    
    if(checkPalindrome(head)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}