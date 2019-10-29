/**
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode root(-1);
        ListNode* p = &root;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        int next = 0;
        while (p1 != NULL && p2 != NULL) {
            int sum = p1->val + p2->val + next;
            if (sum >= 10 ) {
                sum = sum - 10;
                next = 1;
            } else {
                next = 0;
            }
            p->next = new ListNode(sum);
            p = p->next;
            p1 = p1->next;
            p2 = p2->next;
        }

        while (p1 != NULL) {
            int sum = p1->val + next;
            if (sum >= 10 ) {
                sum = sum - 10;
                next = 1;
            } else {
                next = 0;
            }
            p->next = new ListNode(sum);
            p = p->next;
            p1 = p1->next;
        }

        while (p2 != NULL) {
            int sum = p2->val + next;
            if (sum >= 10 ) {
                sum = sum - 10;
                next = 1;
            } else {
                next = 0;
            }
            p->next = new ListNode(sum);
            p = p->next;
            p2 = p2->next;
        }

        if (next == 1) {
            p->next = new ListNode(1);
        } 
        return root.next;
    }
};
