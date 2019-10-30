/**
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-k-sorted-lists
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        // 分治，对于0,1,2三种情况特殊处理
        if (len == 0) {
            return NULL;
        } else if (len == 1) {
            return lists[0];
        } else if (len == 2) {
            return mergeTwoLists(lists[0], lists[1]);
        }

        // 超过2，则先分成两段，再治
        int num = len / 2;
        vector<ListNode*> listsA;
        listsA.insert(listsA.begin(), lists.begin(), lists.begin() + num + 1);
        vector<ListNode*> listsB;
        listsB.insert(listsB.begin(), lists.begin() + num + 1, lists.end());
        return mergeTwoLists(mergeKLists(listsA), mergeKLists(listsB));
    }

    // 合并两个链表
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode root(-1);
        ListNode* cur = &root;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }

        if (l1 != NULL) {
            cur->next = l1;
        }
        if (l2 != NULL) {
            cur->next = l2;
        }
        return root.next;
    }
};
