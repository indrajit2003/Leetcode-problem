/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void findpath1(TreeNode* root, TreeNode* p,vector<int>&ans){
         if(root->val == p->val){
            ans.push_back(root->val);
            return;
        }

        ans.push_back(root->val);
        if(p->val<root->val)
        findpath1(root->left,p,ans);
        else
        findpath1(root->right,p,ans);
    }
    void findpath2(TreeNode* root, TreeNode* q,vector<int>&ans){
        if(root->val == q->val){
            ans.push_back(root->val);
            return;
        }
        ans.push_back(root->val);
        if(q->val<root->val)
        findpath1(root->left,q,ans);
        else
        findpath1(root->right,q,ans);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val==p->val or root->val==q->val) return root;
        vector<int>ans1;
        vector<int>ans2;
        findpath1(root,p,ans1);
        findpath2(root,q,ans2);
        if(ans1.size()<ans2.size()){
            while(ans1.size()!= ans2.size())
            ans1.push_back(INT_MAX);
        }
         if(ans2.size()<ans1.size()){
            while(ans2.size()!= ans1.size())
            ans2.push_back(INT_MAX);
        }
        TreeNode* temp = new TreeNode(NULL);
        for(int i=1;i<ans1.size();i++){
            if(ans1[i]!=ans2[i]){
            TreeNode* temp1 =new TreeNode (ans1[i-1]);
            temp = temp1;
            break;
            }
        }
        return temp;
        
    }
};