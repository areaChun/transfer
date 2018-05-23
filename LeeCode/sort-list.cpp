/**
时间限制：1秒 空间限制：32768K 热度指数：34831
题目描述

Sort a linked list in O(n log n) time using constant space complexity.


 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
技巧：
1）找到链表中点 （快慢指针思路，快指针一次走两步，慢指针一次走一步，快指针在链表末尾时，慢指针恰好在链表中点）；
2）注意边界值和递归或循环判断调条件。如findMiddle中while (runner != NULL && runner->next != NULL)，
   sortList中的if (head == NULL || head->next == NULL)
3）这题用归并
*/


class Solution {
public:

ListNode* findMiddle(ListNode* head) {

	ListNode* chaser = head;
	ListNode* runner = head->next;
	while (runner != NULL && runner->next != NULL) {
		chaser = chaser->next;
		runner = runner->next->next;
	}
	return chaser;
	
}

ListNode* mergeList(ListNode* left, ListNode* right) {
	ListNode* head;
	ListNode* temp;
	if (left->val < right->val) {
		head = left;
		left = left->next;
	}
	else {
		head = right;
		right = right->next;
	}
	temp = head;
	while (left&&right) {
		if (left->val < right->val) {
			temp->next = left;
			left = left->next;
		}
		else {
			temp->next = right;
			right = right->next;
		}
		temp = temp->next;
	}
	if (left != NULL)
		temp->next = left;
	if (right != NULL)
		temp->next = right;
	
	return head;
}

ListNode* sortList(ListNode *head) {
	if (head == NULL || head->next == NULL)
		return head;
	ListNode* middle = findMiddle(head);
	//cout << "middle: " << middle->val << endl;
	//int c;
	//cin >> c;
	ListNode* right = sortList(middle->next);
	middle->next = NULL;
	ListNode* left = sortList(head);
	return mergeList(left, right);

	
}

};