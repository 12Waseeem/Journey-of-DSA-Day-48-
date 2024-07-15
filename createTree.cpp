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
    TreeNode* createTree(vector<vector<int>>&descriptions) {
        unordered_map<int, TreeNode*>mp;
        unordered_set<int>children;
        for(auto des:descriptions){
            int parentVal = des[0];
            int childVal = des[1];
            bool isLeft =(des[2]==1);
            if(mp.find(parentVal) == mp.end()){
                TreeNode* temp = new TreeNode(parentVal);
                mp[parentVal]=temp;
            }
            if(mp.find(childVal) == mp.end()){
                TreeNode* temp = new TreeNode(childVal);
                mp[childVal]=temp;
            }
            
            if(isLeft){
                mp[parentVal]->left= mp[childVal];
            }
              else{
                mp[parentVal]->right= mp[childVal];
            }
            children.insert(childVal);
        }
         TreeNode* root = nullptr;
        for (const auto& node : mp) {
            if (children.find(node.first) == children.end()) {
                root = node.second;
                break;
            }
        }
        
        return root;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        return createTree(descriptions);
    }
};
