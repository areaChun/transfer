/* From leeCode && 牛客网
时间限制：1秒 空间限制：32768K 热度指数：15788
本题知识点： 链表 leetcode

题目描述

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */


 /*
Note:random指针是指向本List中的Node的，因此要先新建了副本，才能把副本的random指向新的副本节点。
     用for把判断语句、初始值、变量赋值写在一行比较简洁
     同时，old=old->next=copy->next;语句很好的实现链表中的赋值和Node的移动，代码更短。
     思路是：复制新的副本Node，赋值副本节点中的random，新旧节点分开
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head)
            return head;
        RandomListNode *copy,*old;
        for(old=head;old;old=old->next){
            copy = new RandomListNode(old->label);
            copy->next = old->next;
            old = old->next = copy;
        }
        for(old=head;old;old=old->next->next){
            copy=old->next;
            copy->random=old->random?old->random->next:NULL;
        }
        /*
        for(old=head,head=copy=head->next;copy->next;){
            
            old=old->next=copy->next;
            copy=copy->next=old->next;
        }
        old->next=NULL;
        */
        
        for(old=head,head=copy=head->next;old;){
            
            old=old->next=copy->next;
            copy=copy->next=(old?old->next:NULL);
        }
        
        return head;
        
    }
};