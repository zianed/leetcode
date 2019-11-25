/**
将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

给定有序数组: [-10,-3,0,5,9],

一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree
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

// 数据分为左右两部分，左边放在left，右边放在right
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        return dfs(nums, 0, nums.size() - 1);
    }
    
    TreeNode* dfs(vector<int>& nums, int i, int j)
    {
        if (i > j) {
            return nullptr;
        }
        int m = (i + j) / 2;
        TreeNode* node = new TreeNode(nums[m]);
        node->left = dfs(nums, i, m - 1);
        node->right = dfs(nums, m + 1, j);
        return node;
    }
};
