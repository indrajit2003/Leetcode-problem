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
    void pathSum(TreeNode* root , int targetSum,bool &flag , int &sum){
        if(!root) return;

        sum+=root->val;
        if(!root->left and !root->right){
            if(sum==targetSum){
                flag=true;
            }
        }
        pathSum(root->left,targetSum,flag,sum);
        pathSum(root->right,targetSum,flag,sum);
        sum-=root->val;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        if(!root->left and !root->right){
            if(root->val == targetSum)
            return true;
        }
        bool flag = false;
        int sum=0;
        pathSum(root,targetSum,flag,sum);
        return flag;
    }
};