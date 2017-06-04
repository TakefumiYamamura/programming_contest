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
private:
    int minimum_difference;
public:
    void recursive(int min_v, int max_v, TreeNode* cur){
        if(cur == NULL) return;
        minimum_difference = min(minimum_difference, min(cur->val - min_v, max_v - cur->val));
        recursive(min_v, cur->val, cur->left);
        recursive(cur->val, max_v, cur->right);
    }
    int getMinimumDifference(TreeNode* root) {
        minimum_difference = INT_MAX;
        recursive(INT_MIN/2, INT_MAX/2, root);
        return minimum_difference;
    }
};
