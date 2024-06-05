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

class LinkedList{
public:
    Node* head;
    Node* tail;
    int size;

    LinkedList(){
        head=tail=NULL;
        size=0;
    }

    void insertAtEnd(int val){
        Node* temp=new Node(val);
        if(size==0) head=tail=temp;
        else{
            tail->next=temp;
            tail=temp;
        }
        size++;
    }

    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    void insertAtHead(int val){
        Node* temp=new Node(val);
        if(size==0) head=tail=temp;
        else{
            temp->next=head;
            head=temp;
        }
        size++;
    }
    void insertAt(int idx,int val){
        
        if(idx==0) insertAtHead(val);
        else if(idx==size) insertAtEnd(val);
        else if(idx<0 || idx>size){
            cout<<"Invalid Index"<<endl;
            return;
        }
        else{
            Node* temp=new Node(val);
            Node* curr=head;
            while(--idx){
                curr=curr->next;
            }
            temp->next=curr->next;
            curr->next=temp;
            size++;
        }
    }

    void deleteAtHead(){
        if(size==0){
            cout<<"List Empty"<<endl;
        }
        else if(size==1){
            head=tail=NULL;
            size--;
        }
        else{
            head=head->next;
            size--;
        }
    }

    void deleteAtEnd(){
        if(size==0){
            cout<<"List Empty"<<endl;
        }
        else if(size==1){
            head=tail=NULL;
            size--;
        }
        else{
            Node* temp=head;
            while(temp->next!=tail){
                temp=temp->next;
            }
            temp->next=NULL;
            size--;
        }
    }
    void deleteAtIndex(int idx){
        if(idx==0) deleteAtHead();
        else if(idx==size-1) deleteAtEnd();
        else if(idx<0 || idx>size-1){
            cout<<"Invalid Index"<<endl;
            return;
        }
        else{
            Node* temp=head;
            while(--idx){
                temp=temp->next;
            }
            temp->next=temp->next->next;
        }
    }
    int getAtIndex(int idx){
        if(idx==0) return head->val;
        else if(idx==size-1) return tail->val;
        else if(idx<0 || idx>size-1) return -1;
        else{
            Node* temp=head;
            while(--idx){
                temp=temp->next;
            }
            return temp->val;
        }
        
        
    }
};

int main(){

    LinkedList ll;


    return 0;
}