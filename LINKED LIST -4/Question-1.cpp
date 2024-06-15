# include <iostream>
using namespace std;
struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;

        ListNode* slow=head;
        ListNode* fast=head->next;
        ListNode* dummy=new ListNode(-69);
        ListNode* temp=dummy;
        temp->next=head;
        while(slow && fast){
            temp->next=fast;
            slow->next=fast->next;
            fast->next=slow;
            if(slow) slow=slow->next;
            temp=fast->next;
            
            if(slow) fast=slow->next;
        }
        return dummy->next;

    }
};