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
    TreeNode* insertBST(TreeNode* root,int target){
        if(!root) return new TreeNode(target);

        if(root->val > target){
            root->left = insertBST(root->left,target);
        }else{
            root->right = insertBST(root->right,target);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i=1;i<preorder.size();i++){
            insertBST(root,preorder[i]);
        }
        return root;
    }
};