/**
给定一个 N 叉树，找到其最大深度。

最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。

例如，给定一个 3叉树 :

 



 

我们应返回其最大深度，3。

说明:

树的深度不会超过 1000。
树的节点总不会超过 5000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-depth-of-n-ary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

// 广度优先搜索
class Solution {
public:
    int maxDepth(Node* root)
    {
        int depth = 0;
        if (root == nullptr) {
            return depth;
        }
        queue<Node*> qPath;
        qPath.push(root);
        while (!qPath.empty()) {
            depth++;
            int len = qPath.size();
            for (int i = 0; i < len; i++) {
                Node* node = qPath.front();
                qPath.pop();
                for (Node *n : node->children) {
                    if (n != nullptr) {
                        qPath.push(n);
                    }
                }
            }
        }
        return depth;
    }
};

// 深度优先搜索
class Solution {
public:
    int maxDepth(Node* root) {
        if (root == NULL) {
            return 0;
        }
        
        int maxV = 0;
        for (Node* node: root->children) {
            maxV = max(maxV, maxDepth(node));
        }
        return maxV + 1;
    }
};
