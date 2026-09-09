/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void level(TreeNode* root,vector<vector<int>>&ans){
        if(!root) return;

        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            vector<int>temp;
            for(int i=0;i<s;i++){
              TreeNode* k = q.front();
              temp.push_back(k->val);
              q.pop();
              if(k->left)
              q.push(k->left);
              if(k->right)
              q.push(k->right);
            }
            ans.push_back(temp);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        level(root,ans);
        return ans;
    }
};