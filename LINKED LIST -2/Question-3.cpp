# include<iostream>
using namespace std;

class ListNode{
public: 
    int val;
    ListNode* next;
};

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* start=head;
        ListNode* end=head;
        ListNode* temp=head;

        for(int i=1;i<=k;i++) end=end->next;
        while(end!=NULL){
            end=end->next;
            temp=temp->next;
        }
        for(int i=1;i<k;i++) start=start->next;

        int tempo=start->val;
        start->val=temp->val;
        temp->val=tempo;
        return head;
    }
};

