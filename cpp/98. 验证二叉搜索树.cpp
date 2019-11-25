/**
给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
示例 1:

输入:
    2
   / \
  1   3
输出: true
示例 2:

输入:
    5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/validate-binary-search-tree
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
    bool isValidBST(TreeNode* root) {
        return dfs(root, LLONG_MIN, LLONG_MAX);
    }
    
    bool dfs(TreeNode* root, long long l, long long u)
    {
        if (root == nullptr) {
            return true;
        }
        if (root-> val < u &&
            root-> val > l &&
            dfs(root->left, l, root->val) &&
            dfs(root->right, root->val, u)) {
            return true;
        }
        return false;
    }
};


class Solution {
public:
    // pre用来记录左边的这个值
    TreeNode* pre = nullptr;
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        // left
        if(!isValidBST(root->left)) {
            return false;
        }
        // root
        if (pre && pre->val >= root->val) {
            return false;
        }
        pre = root;
        // right
        if(!isValidBST(root->right)) {
            return false;
        }
        return true;
    }
};
