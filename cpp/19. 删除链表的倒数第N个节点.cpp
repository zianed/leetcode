/**
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode root(-1);
        root.next = head;
        ListNode* pre = &root;
        ListNode* post = pre;

        // 向后移动n个
        int i = 0;
        while (post != NULL && i <= n) {
            post = post->next;
            i++;
        }
        // cout << post->val <<endl;
        
        while (post != NULL) {
            pre = pre->next;
            post = post->next;
        }
        // cout << pre->val <<endl;

        pre->next = pre->next->next;
        return root.next;
    }
};

