# include<iostream>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};

int main(){

    Node* a=new Node(3);
    Node* b=new Node(2);
    Node* c=new Node(0);
    Node* d=new Node(-4);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=b;

    Node* head=a;
    Node* slow=head;
    Node* fast=head;

    while(fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow) break;
    }

    Node* ptr=slow;
    int count=1;
    while(slow->next!=ptr){
        count++;
        slow=slow->next;
    }
    cout<<count;



    return 0;
}