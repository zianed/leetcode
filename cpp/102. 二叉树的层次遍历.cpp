/**
给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) {
            return res;
        }
        queue<TreeNode*> queueNode;
        queueNode.push(root);
        while (!queueNode.empty()) {
            // 每一层放的是上一层的所有子节点，使用队列
            vector<int> vec;
            int len = queueNode.size();
            for (int i = 0; i < len; i++) {
                TreeNode* node = queueNode.front();
                queueNode.pop();
                vec.push_back(node->val);
                if (node->left != NULL) {
                    queueNode.push(node->left);
                }
                if (node->right != NULL) {
                    queueNode.push(node->right);
                }
            }
            res.push_back(vec);
        }
        return res;
    }
};