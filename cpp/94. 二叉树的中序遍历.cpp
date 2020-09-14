/**
给定一个二叉树，返回它的中序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-inorder-traversal
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) {
            return res;
        }

        if (root->left != NULL) {
            vector<int> leftNode = inorderTraversal(root->left);
            res.insert(res.end(), leftNode.begin(), leftNode.end());
        }
        res.push_back(root->val);
        if (root->right != NULL) {
            vector<int> rightNode = inorderTraversal(root->right);
            res.insert(res.end(), rightNode.begin(), rightNode.end());
        }
        return res;
    }
};

// 非递归解法
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) {
            return res;
        }
        stack<TreeNode*> stackNode;
        while (!stackNode.empty() || root != NULL) {
            if (root != NULL) {
                // 将最左节点放入
                stackNode.push(root);
                root = root->left;
            } else {
                // 取得当前节点
                root = stackNode.top();
                stackNode.pop();
                res.push_back(root->val);
                // 处理右节点，(右节点是空的时候，就会出栈，其实就是处理父节点)
                root = root->right;
            }
        }
        return res;
    }
};


// 保存遍历历史
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) {
            return res;
        }
        stack<TreeNode*> stackNode;
        set<TreeNode*> visitied;
        stackNode.push(root);
        while (!stackNode.empty()) {
            TreeNode* node = stackNode.top();
            if (node->left != NULL && visitied.count(node->left) == 0) {
                stackNode.push(node->left);
                continue;
            }
            res.push_back(node->val);
            visitied.insert(node);
            // cout << node->val << endl;
            stackNode.pop();
            if (node->right != NULL && visitied.count(node->right) == 0) {
                stackNode.push(node->right);
            }
        }

        return res;
    }
};

