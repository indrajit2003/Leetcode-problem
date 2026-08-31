/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans;
        vector<int>ans1(2,-1);
        if(head->next->next==NULL) 
        return ans1;

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* p = NULL;
        if(curr->next)
        p = curr->next;

        int c=1;
        while(curr->next){
            if(curr->val > prev->val and curr->val > p->val)
            ans.push_back(c);
            
            if(curr->val < prev->val and curr->val < p->val)
            ans.push_back(c);

            prev = curr;
            curr = p;
            if(curr->next)
            p = curr->next;
            c = c+1;
        }
        if(ans.size()==0 or ans.size()==1) 
        return ans1;

        ans1[1] = ans.back() - ans.front();

        int m = INT_MAX;
        for(int i = 1; i < ans.size(); i++){
           m = min(m, ans[i] - ans[i-1]);
        }
        ans1[0]=m;

        return ans1;
    }
};