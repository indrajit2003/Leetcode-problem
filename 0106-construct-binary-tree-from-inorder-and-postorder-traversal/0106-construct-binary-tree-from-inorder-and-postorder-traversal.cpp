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
    int Find(vector<int>& inorder,int target,int start,int end){
        for(int i=start;i<=end;i++){
            if(inorder[i]==target){
                return i;
            }
        }
        return -1;
    }
    TreeNode* tree(vector<int>& preorder, vector<int>& inorder,int instart,int inend,int index){
        if(instart>inend) return NULL;

        TreeNode* root = new TreeNode(preorder[index]);
        int pos = Find(inorder,preorder[index],instart,inend);
        root->right = tree(preorder,inorder,pos+1,inend,index+1);
        root->left = tree(preorder,inorder,instart,pos-1,index+(inend-pos)+1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        reverse(postorder.begin(),postorder.end());
        int n=inorder.size();
        return tree(postorder,inorder,0,n-1,0);
    }
};