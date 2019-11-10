/**
给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层次遍历如下：

[
  [3],
  [20,9],
  [15,7]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal
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

// 使用队列+逆序 
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) {
            return res;
        }
        queue<TreeNode*> qNode;
        qNode.push(root);
        int index = 1;
        while (!qNode.empty()) {
            vector<int> vec;
            int len = qNode.size();
            for (int i = 0; i < len; i++) {
                TreeNode* node = qNode.front();
                qNode.pop();
                vec.push_back(node->val);
                if (node->left != NULL) {
                    qNode.push(node->left);
                }
                if (node->right != NULL) {
                    qNode.push(node->right);
                }
            }
            // 对于偶数层，逆序
            if (index % 2 == 0) {
                reverse(vec.begin(), vec.end());
            }
            index++;
            res.push_back(vec);
        }
        return res;
    }
};

// 使用栈
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) {
            return res;
        }
        // 奇数层
        stack<TreeNode*> sNode1;
        // 偶数层
        stack<TreeNode*> sNode2;
        sNode1.push(root);
        while (!sNode1.empty() || !sNode2.empty()) {
            vector<int> vec;
            if (!sNode1.empty()) {
                while (!sNode1.empty()) {
                    TreeNode* node = sNode1.top();
                    sNode1.pop();
                    vec.push_back(node->val);
                    // 偶数层右->左
                    if (node->left != NULL) {
                        sNode2.push(node->left);
                    }
                    if (node->right != NULL) {
                        sNode2.push(node->right);
                    }
                }
            } else if (!sNode2.empty()) {
                while (!sNode2.empty()) {
                    TreeNode* node = sNode2.top();
                    sNode2.pop();
                    vec.push_back(node->val);
                    // 奇数层左->右
                    if (node->right != NULL) {
                        sNode1.push(node->right);
                    }
                    if (node->left != NULL) {
                        sNode1.push(node->left);
                    }
                }
            }
            res.push_back(vec);
        }
        return res;
    }
};


