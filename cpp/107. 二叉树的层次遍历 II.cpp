/**
给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其自底向上的层次遍历为：

[
  [15,7],
  [9,20],
  [3]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
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
        // 逆序
        reverse(res.begin(), res.end());
        return res;
    }
};
