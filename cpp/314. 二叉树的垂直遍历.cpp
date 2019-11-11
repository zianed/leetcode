/**
给定一个二叉树，返回其结点 垂直方向（从上到下，逐列）遍历的值。

如果两个结点在同一行和列，那么顺序则为 从左到右。

示例 1：

输入: [3,9,20,null,null,15,7]

   3
  /\
 /  \
9   20
    /\
   /  \
  15   7 

输出:

[
  [9],
  [3,15],
  [20],
  [7]
]
示例 2:

输入: [3,9,8,4,0,1,7]

     3
    /\
   /  \
  9    8
  /\   /\
 /  \ /  \
4   0 1   7 

输出:

[
  [4],
  [9],
  [3,0,1],
  [8],
  [7]
]
示例 3:

输入: [3,9,8,4,0,1,7,null,null,null,2,5]（注意：0 的右侧子节点为 2，1 的左侧子节点为 5）

     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7
    /\
   /  \
   5   2

输出:

[
  [4],
  [9,5],
  [3,0,1],
  [8,2],
  [7]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-vertical-order-traversal
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

// 使用队列遍历，使用pair<int, TreeNode*>存储
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) {
            return res;
        }
        map<int, vector<int>> mValue;
        queue<pair<int, TreeNode*>> qNode;
        qNode.push(pair<int, TreeNode*>(0, root));
        while (!qNode.empty()) {
            auto it = qNode.front();
            qNode.pop();
            int index = it.first;
            TreeNode* node = it.second;
            mValue[index].push_back(node->val);
            if (node->left != NULL) {
                qNode.push(pair<int, TreeNode*>(index - 1, node->left));
            }
            if (node->right != NULL) {
                qNode.push(pair<int, TreeNode*>(index + 1, node->right));
            }
        }
        for (auto it = mValue.begin(); it != mValue.end(); it++) {
            res.push_back(it->second);
        }
        return res;
    }
};

// 使用dfs遍历multimap<层高，数据>存储
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        map<int, multimap<int, int>> mValue;
        dfs(root, 0, 1, mValue);
        for (auto it = mValue.begin(); it != mValue.end(); it++) {
            vector<int> vec;
            auto mData = it->second;
            for (auto iter = mData.begin(); iter != mData.end(); iter++) {
                vec.push_back(iter->second);
            }
            res.push_back(vec);
        }
        return res;
    }
    
    void dfs(TreeNode* node, int index, int level, map<int, multimap<int, int>> &mValue) {
        if (node == NULL) {
            return;
        }
        (mValue[index]).insert(pair<int, int>(level, node->val));
        dfs(node->left, index - 1, level + 1, mValue);
        dfs(node->right, index + 1, level + 1, mValue);
    }
};

