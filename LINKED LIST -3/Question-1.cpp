# include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;     ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        if(head->next->next==NULL){
            if(head->val==head->next->val) return NULL;
            else return head;
        }

        ListNode* newHead= new ListNode(-101);
        ListNode* temp=newHead;
        ListNode* slow=head;
        ListNode* fast=head->next;

        while(fast){
            if(slow->val==fast->val){
                int x=slow->val;
                ListNode* t=slow;
                while(slow!=NULL && slow->val==x){
                    slow=slow->next;
                }
                if(slow==NULL) break;
                fast=slow->next;
            }
            else{
                ListNode* c=new ListNode(slow->val);
                temp->next=c;
                temp=temp->next;
                slow=slow->next;
                fast=fast->next;
            }
        }
        if(slow){
            ListNode* c=new ListNode(slow->val);
            temp->next=c;
            temp=temp->next;
        }
        

        
        
        return newHead->next;
    }
};