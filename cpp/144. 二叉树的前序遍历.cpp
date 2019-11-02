/**
给定一个二叉树，返回它的 前序 遍历。

 示例:

输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [1,2,3]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-preorder-traversal
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
// 递归解法
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) {
            return res;
        }

        res.push_back(root->val);
        if (root->left != NULL) {
            vector<int> leftNode = preorderTraversal(root->left);
            res.insert(res.end(), leftNode.begin(), leftNode.end());
        }
        if (root->right != NULL) {
            vector<int> rightNode = preorderTraversal(root->right);
            res.insert(res.end(), rightNode.begin(), rightNode.end());
        }
        return res;
    }
};

// 非递归
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) {
            return res;
        }
        stack<TreeNode*> stackNode;
        stackNode.push(root);
        while (!stackNode.empty()) {
            // 先处理当前节点
            root = stackNode.top();
            stackNode.pop();
            res.push_back(root->val);
            // 右侧后处理，右侧先压入栈
            if (root->right != NULL) {
                stackNode.push(root->right);
            }
            // 左侧后处理，左侧后压入栈
            if (root->left != NULL) {
                stackNode.push(root->left);
            }
        }
        return res;
    }
};
