/**
给定一个 N 叉树，返回其节点值的后序遍历。

例如，给定一个 3叉树 :

 



 

返回其后序遍历: [5,6,3,2,4,1].

 

说明: 递归法很简单，你可以使用迭代法完成此题吗?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/n-ary-tree-postorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

// 递归
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        if (root == NULL) {
            return res;
        }
        auto &children = root->children;
        if (!children.empty())) {
            for (Node* node : children) {
                vector<int> result = postorder(node);
                res.insert(res.end(), result.begin(), result.end());
            }
        }
        res.push_back(root->val);
        return res;
    }
};

// 非递归
// 子节点1， 子节点2， 根
// 反转后就是根，子节点2，子节点1，利用栈的性质，计算后再反转回来结果
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        if (root == NULL) {
            return res;
        }
        stack<Node*> stackNode;
        stackNode.push(root);
        while (!stackNode.empty()) {
            // 处理根
            Node* node = stackNode.top();
            stackNode.pop();
            res.push_back(node->val);
            // 按顺序处理
            for (Node* node : node->children) {
                stackNode.push(node);
            }
        }
        // 反转数据
        reverse(res.begin(), res.end());
        return res;
    }
};

