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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* fast=head->next;
        ListNode* slow=head;

        ListNode* dummy=new ListNode(-100);
        ListNode* temp=dummy;

        while(fast!=NULL){
            if(fast->val==0){
                int x=0;
                while(slow!=fast){
                    x+=slow->val;
                    slow=slow->next;
                }
                ListNode* c=new ListNode(x);
                temp->next=c;
                temp=temp->next;
            }
         fast=fast->next;
        }
        return dummy->next;

    }
};