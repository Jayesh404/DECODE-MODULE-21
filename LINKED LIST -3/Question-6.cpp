# include <iostream>
# include <limits.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;     ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    ListNode* reverseList(ListNode* head) {
        //ITERATIVE
        if(head==NULL || head->next==NULL) return head;
        ListNode* temp=head;
        ListNode* left=NULL;
        ListNode* right=head->next;
        while(right!=NULL){
            temp->next=left;
            left=temp;
            temp=right;
            right=right->next;
        }
        temp->next=left;
        return temp;
    }
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* head2=reverseList(slow->next);
        slow->next=NULL;

        ListNode* temp1=head;
        ListNode* temp2=head2;

        int max=INT_MIN;
        while(temp2){
            int x=temp1->val+temp2->val;
            if(x>max) max=x;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return max;
    }
};