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
	if(!head){
		node*n=new node(data);
		head=tail=n;
	}
	else{
		node*n=new node(data);
		tail->next=n;
		tail=n;
	}
}
node*midelement(node*&head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node*slow=head;
    node*fast=head->next;
     while(fast and fast->next){
         fast=fast->next;
         slow=slow->next;
     }
     return slow;
}
node*merge(node*a,node*b){
    // base case
    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }
    
    node*c;
    if(a->data<b->data){
        c=a;
        c->next=merge(a->next,b);
    }
    else{
        c=b;
        c->next=merge(a,b->next);
    }
    return c;
}
node*mergeSort(node*head){
    //base case
    if(head==NULL || head->next==NULL){
        return head;
    }

    //divide
    node*m=midelement(head);
    node*a=head;
    node*b=m->next;
    m->next=NULL;
    // Sort
    a=mergeSort(a);
    b=mergeSort(b);

    //merge
    node*newhead=merge(a,b);
    return newhead;

}
void display(node*head){
	while(head){
		cout<<head->data<<"-->";
		head=head->next;
	}
    cout<<"NULL"<<endl;
}
void removeDuplicates(node*&newhead){
    if(newhead==NULL or newhead->next==NULL){
            return ;
        }
        node* prev=newhead;
        node* curr=newhead->next;
        while(curr->next!=NULL){
            if(prev->data==curr->data){
                prev->next=curr->next;
                delete curr;
                curr=prev->next;
            }
            else{
                
                curr=curr->next;
                prev=prev->next;
            }
            
        }
        if(prev->data==curr->data){
                prev->next=NULL;
                delete curr;
        }
}
int main(){
    node*head=NULL;
    node*tail=NULL;
    insertatEnd(head,tail,1);
    insertatEnd(head,tail,3);
    insertatEnd(head,tail,2);
    insertatEnd(head,tail,3);
    insertatEnd(head,tail,4);
    insertatEnd(head,tail,3);
    insertatEnd(head,tail,1);
    insertatEnd(head,tail,7);
    
    display(head);

    cout<<"After Sorting..."<<endl;
    node*newhead=mergeSort(head);
    display(newhead);

    removeDuplicates(newhead); 

    display(newhead);

}