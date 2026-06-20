/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
    if(root == NULL)
        return "";

    string ans;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty())
    {
        TreeNode* front = q.front();
        q.pop();

        if(front == NULL)
        {
            ans += "N,";
            continue;
        }

        ans += to_string(front->val) + ",";

        q.push(front->left);
        q.push(front->right);
    }
    return ans;
        }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
{
    if(data.size() == 0)
        return NULL;

    stringstream ss(data);
    string str;

    getline(ss, str, ',');

    TreeNode* root = new TreeNode(stoi(str));

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty())
    {
        TreeNode* parent = q.front();
        q.pop();

        getline(ss, str, ',');

        if(str != "N")
        {
            TreeNode* leftNode =
                new TreeNode(stoi(str));

            parent->left = leftNode;
            q.push(leftNode);
        }

        getline(ss, str, ',');

        if(str != "N")
        {
            TreeNode* rightNode =
                new TreeNode(stoi(str));

            parent->right = rightNode;
            q.push(rightNode);
        }
    }

    return root;
}
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));