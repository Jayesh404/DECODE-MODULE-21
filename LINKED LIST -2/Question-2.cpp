# include<iostream>
using namespace std;

class ListNode{
public: 
    int val;
    ListNode* next;
};

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp1=list1;
        ListNode* temp2=list1;
        for(int i=1;i<a;i++) temp1=temp1->next;
        for(int i=1;i<=b;i++) temp2=temp2->next;

        ListNode* temp=list2;
        while(temp->next!=NULL) temp=temp->next;

        temp1->next=list2;
        temp->next=temp2->next;
        return list1;
    }
};