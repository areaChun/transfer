/** From leeCode && 牛客网
时间限制：1秒 空间限制：32768K 热度指数：17864
本题知识点： 链表 leetcode

题目描述

Given a linked list, return the node where the cycle begins. If there is no cycle, returnnull.

Follow up:
Can you solve it without using extra space?


*/
/*
本solution位参考大神
链接：https://www.nowcoder.com/questionTerminal/6e630519bf86480296d0f1c868d425ad
来源：牛客网

思路：
1）同linked-list-cycle-i一题，使用快慢指针方法，判定是否存在环，并记录两指针相遇位置(Z)；
2）将两指针分别放在链表头(X)和相遇位置(Z)，并改为相同速度推进，则两指针在环开始位置相遇(Y)。

证明如下：
如下图所示，X,Y,Z分别为链表起始位置，环开始位置和两指针相遇位置，则根据快指针速度为慢指针速度的两倍，可以得出：

        X            a         Y 
        ——————————————————————|---、
                             /     \ b
                            |       \__ Z
                          c \       /
                             \_____/ 


2*(a + b) = a + b + n * (b + c)；即
a=(n - 1) * b + n * c = (n - 1)(b + c) +c;
PS:根据公式一定会相遇，只是fast指针会循环n次。而slow不会循环，直接在a+b处相遇。可以把b= m(b+c)+b代进去，最后依然会在
fast的(n-m)次循环相遇。

注意到b+c恰好为环的长度，故可以推出，如将此时两指针分别放在起始位置和相遇位置，并以相同速度前进，当一个指针走完距离a时，另一个指针恰好走出 绕环n-1圈加上c的距离。
故两指针会在环开始位置相遇。
*/

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head)
            return head;
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast&&fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(fast==slow)
                break;
        }
        if(!fast||!fast->next)
            return NULL;
        slow = head;
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
        
    }
};