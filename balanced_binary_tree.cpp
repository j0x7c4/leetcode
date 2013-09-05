/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ( root == NULL ) return true;
        int l,r;
        l = calcHeight(root->left);
        r = calcHeight(root->right);
        if ( l<0 || r<0 || abs(l-r)>1 ) return false;
        return true;
        
    
    }
    int calcHeight(TreeNode* root) {
        if ( root == NULL ) return 0;
        int l,r;
        l = calcHeight(root->left);
        r = calcHeight(root->right);
        if ( l<0 || r<0 || abs(l-r)>1 ) return -1;
        return max(l,r)+1;
    }
};