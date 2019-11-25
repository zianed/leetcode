/**
给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree
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

// 深度优先搜索
class Solution {
public:
    int maxDepth(TreeNode* root)
    {
        if (root == 0) {
            return 0;
        }
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

// 广度优先搜索
class Solution {
public:
    int maxDepth(TreeNode* root)
    {
        int depth = 0;
        if (root == 0) {
            return depth;
        }
        queue<TreeNode*> qPath;
        qPath.push(root);
        while (!qPath.empty()) {
            depth++;
            int len = qPath.size();
            for (int i = 0; i < len; i++) {
                TreeNode* node = qPath.front();
                qPath.pop();
                if (node->left != NULL) {
                    qPath.push(node->left);
                }
                if (node->right != NULL) {
                    qPath.push(node->right);
                }
            }
        }
        return depth;
    }
};


