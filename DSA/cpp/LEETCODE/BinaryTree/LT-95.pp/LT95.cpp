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
    vector<TreeNode*>generateTrees(int n){
        if(n == 0) return {};
        return build(1, n);
    }   
    vector<TreeNode*> build(int start, int end){
        vector<TreeNode*> result;
        if(start > end){
            result.push_back(NULL);
            return result;
        } 

        for(int i = start; i <= end; i++){
            
            vector<TreeNode*> leftsubtree = build(start, i - 1);
            vector<TreeNode*> rightsubtree = build(i + 1, end);
            for(TreeNode* left: leftsubtree){
                for(TreeNode* right : rightsubtree){
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
            }
        }
        return result;
    } 
};