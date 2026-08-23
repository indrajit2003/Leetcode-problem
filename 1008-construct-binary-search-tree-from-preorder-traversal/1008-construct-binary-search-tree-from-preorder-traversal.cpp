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
    TreeNode* BST(vector<int>preorder,int lower,int upper,int &index){
           if(index==preorder.size() or preorder[index]<lower or preorder[index]>upper)
           return NULL;

           TreeNode* temp = new TreeNode(preorder[index++]);
           temp->left = BST(preorder,lower,temp->val,index);
           temp->right = BST(preorder,temp->val,upper,index);
           return temp;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int lower = INT_MIN;
        int upper = INT_MAX;
        int index=0;
        return BST(preorder,lower,upper,index);
    }
};