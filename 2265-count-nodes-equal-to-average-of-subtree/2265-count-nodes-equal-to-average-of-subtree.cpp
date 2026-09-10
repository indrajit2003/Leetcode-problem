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
    int findSum(TreeNode* root,int &count){
        if(!root) return 0;

        count+=1;
        return root->val+findSum(root->left,count)+findSum(root->right,count);
    }
    void solve(TreeNode* root,int &res){
        if(!root) return;
        int count=0;
        int sum = findSum(root,count);
        if(root->val==sum/count) res+=1;
        solve(root->left,res);
        solve(root->right,res);
    }
    int averageOfSubtree(TreeNode* root) {
        if(!root->left and !root->right) return 1;
        int res=0;
        solve(root,res);
        return res;
    }
};