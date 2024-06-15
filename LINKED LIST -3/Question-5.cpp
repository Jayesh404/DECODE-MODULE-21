# include <iostream>
# include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;     ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* temp=head;
        int count=0;
        while(temp->next!=NULL){
            count++;
            temp=temp->next;
        }
        int ans=0;
        for(int i=count;i>=0;i--){
            ans=ans+(head->val)*(pow(2,i));
            head=head->next;
        }
        return ans;
    }
};