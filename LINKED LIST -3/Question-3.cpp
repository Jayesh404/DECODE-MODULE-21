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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* head1=head;
        ListNode* head2=head->next;
        ListNode* temp1=head1;
        ListNode* temp2=head2;

        while(temp1->next and temp2->next){
            temp1->next=temp2->next;
            temp1=temp1->next;
            temp2->next=temp1->next;
            temp2=temp2->next;
        }
        temp1->next=head2;
        
        
           
        return head;

    }
};