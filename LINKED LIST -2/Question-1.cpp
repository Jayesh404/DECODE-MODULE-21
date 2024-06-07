# include<iostream>
using namespace std;

class ListNode{
public: 
    int val;
    ListNode* next;
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        if(slow->next==NULL) return NULL;
        while(fast!=NULL and fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* temp=head;

        while(temp->next!=slow){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;
    }
};