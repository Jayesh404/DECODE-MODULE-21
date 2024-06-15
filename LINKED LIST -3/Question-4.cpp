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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1=l1;
        ListNode* t2=l2;

        ListNode* newHead= new ListNode(-1);
        ListNode* temp=newHead;

        int carry=0;
        while(t1!=NULL && t2!=NULL){
            int x=t1->val+t2->val+carry;
            carry=x/10;
            x=x%10;

            ListNode* c=new ListNode(x);
            temp->next=c;
            temp=c;

            t1=t1->next;
            t2=t2->next;

        }

        while(t1){
            int x=t1->val+carry;
            carry=x/10;
            x=x%10;
            ListNode* c=new ListNode(x);
            temp->next=c;
            temp=c;

            t1=t1->next;
        }
        while(t2){
            int x=t2->val+carry;
            carry=x/10;
            x=x%10;
            ListNode* c=new ListNode(x);
            temp->next=c;
            temp=c;
            t2=t2->next;
        }
        while(carry){
            int x=carry;
            carry=x/10;
            x=x%10;
            ListNode* c=new ListNode(x);
            temp->next=c;
            temp=c;

        }

        return newHead->next;

    }
};