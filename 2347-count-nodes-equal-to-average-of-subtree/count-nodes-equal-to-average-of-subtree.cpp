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
private:
pair<int,int> solve(TreeNode*root,int &count)
{
    if(root==NULL) return {0,0};

    pair<int,int>leftsub=solve(root->left,count);
    pair<int,int>rightsub=solve(root->right,count);

    int total_sum=leftsub.first+rightsub.first+(root->val);
    int total_nodes=leftsub.second+rightsub.second+1;//+1 for node itself

    if(total_sum/total_nodes==root->val) count++;

    return {total_sum,total_nodes};
}
public:
    int averageOfSubtree(TreeNode* root) {

        int count=0;

        solve(root,count);
        return count;


        
    }
};