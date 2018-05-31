/** Form leeCode && 牛客网
时间限制：1秒 空间限制：32768K 热度指数：14231
本题知识点： 链表 leetcode

题目描述

Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/
/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
思路：参考 linked-list-cycle-ii
*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)
            return false;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast&&fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast)
                return true;
        }
        return false;
        
    }
};