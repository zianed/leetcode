/**
给定一个二叉树，返回它的 后序 遍历。

示例:

输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [3,2,1]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-postorder-traversal
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

// 递归
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) {
            return res;
        }

        if (root->left != NULL) {
            vector<int> leftNode = preorderTraversal(root->left);
            res.insert(res.end(), leftNode.begin(), leftNode.end());
        }
        if (root->right != NULL) {
            vector<int> rightNode = preorderTraversal(root->right);
            res.insert(res.end(), rightNode.begin(), rightNode.end());
        }
        res.push_back(root->val);
        return res;

    }
};

// 非递归
// 使用一个栈记录待访问的节点
// 增加一个标记记录上次访问过的节点
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) {
            return res;
        }
        TreeNode* last = root;
        stack<TreeNode*> stackNode;
        stackNode.push(root);
        while (!stackNode.empty()) {
            root = stackNode.top();
            // 什么条件下处理数据
            // 1.叶子节点，左右子树都是空
            // 2.左右子节点都被访问过了(右子树被访问过，左子树被访问过同时右子树为空)
            if ((root->left == NULL && root->right == NULL) || (root->left == last && root->right == NULL) || (root->right == last)) {
                stackNode.pop();
                res.push_back(root->val);
                last = root;
            } else {
                if (root->right != NULL) {
                    stackNode.push(root->right);
                }
                if (root->left != NULL) {
                    stackNode.push(root->left);
                }
            }
        }
        return res;
    }
};

// 非递归
// 后序遍历左右根，倒过来就是根右左
// 那就先按前序遍历处理跟右左，然后再reverse倒序
class Solution {
public:
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
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
            // 左侧后处理，左侧后压入栈
            if (root->left != NULL) {
                stackNode.push(root->left);
            }
            // 右侧后处理，右侧先压入栈
            if (root->right != NULL) {
                stackNode.push(root->right);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
