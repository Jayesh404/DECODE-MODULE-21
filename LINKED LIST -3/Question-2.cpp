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
    ListNode* insertionSortList(ListNode* head) {
        if(head->next==NULL) return head;

        ListNode* dummy= new ListNode(-5555,head);

        ListNode* prev=head;
        ListNode* curr=head->next;
        while(curr){
            if(curr->val>=prev->val){
                prev=prev->next;
                curr=curr->next;
                continue;
            }
            else{
                ListNode* temp=dummy;
                while(temp->next->val<=curr->val){
                    temp=temp->next;
                }
                prev->next=curr->next;
                curr->next=temp->next;
                temp->next=curr;
                curr=prev->next;
            }


        }
        return dummy->next;
    }
};