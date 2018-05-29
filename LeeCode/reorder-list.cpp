/** From leecode&&牛客网

时间限制：1秒 空间限制：32768K 热度指数：30542
本题知识点： 链表 leetcode

题目描述

Given a singly linked list L: L 0→L 1→…→L n-1→L n,
reorder it to: L 0→L n →L 1→L n-1→L 2→L n-2→…

You must do this in-place without altering the nodes' values.

For example,
Given{1,2,3,4}, reorder it to{1,4,2,3}.
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
Note:

original: 1->2->3->4->5->6->7->8->9
Step1: 切割。head: 1->2->3->4->5 tail:6->7->8->9
用追赶法找到中间值：

	ListNode *middle = head, *tail = head->next;
	while (tail&&tail->next) {
		middle = middle->next;
		tail = tail->next->next;
	}

	此时Middle指向的是5，但是需要的是tail部分的头节点，所以

	middle = middle->next。

	同时需要Head的尾节点的Next设为NULL。

Step2: tail取反。tail:9->8->7->6
Step3: 插入合并。1->9->2->8->3->7->4->6->5

*/
class Solution {
public:
ListNode* tailList(ListNode *head) {
	ListNode *middle = head, *tail = head->next;
	while (tail&&tail->next) {
		middle = middle->next;
		tail = tail->next->next;
	}
	tail = middle;
	middle = middle->next;
	tail->next = NULL;
	return middle;
}
ListNode* reverseList(ListNode *head) {
	if (!head->next)
		return head;
	ListNode *preNode = head;
	head = head->next;
	preNode->next = NULL;
	while (head&&head->next) {
		ListNode* temp = head->next;
		head->next = preNode;
		preNode = head;
		head = temp;
	}
	head->next = preNode;
	/*ListNode* node = head;
	node = head;
	cout << "\n head: ";
	while (node) {
		cout << node->val << " ";
		node = node->next;
	}*/
	return head;
}
void mergeList(ListNode* head, ListNode* tail) {
	ListNode* index = head;
	while (tail) {
		ListNode* temp = tail->next;
		tail->next = index->next;
		index->next = tail;
		index = index->next->next;
		tail = temp;
	}
}
void reorderList(ListNode *head) {
	if (!head || !head->next)
		return;
	ListNode* tail = tailList(head);
	/*ListNode* node = tail;*/
	//cout << "\n tail: ";
	//while (node) {
	//	cout << node->val << " ";
	//	node = node->next;
	//}
	//node = head;
	//cout << "\n head: ";
	//while (node) {
	//	cout << node->val << " ";
	//	node = node->next;
	//}
	tail = reverseList(tail);
	/*node = tail;
	cout << "\nreverse tail: ";
	while (node) {
		cout << node->val << " ";
		node = node->next;
	}*/
	mergeList(head, tail);
}

};