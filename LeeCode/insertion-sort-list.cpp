/**From leetcode&牛客网

时间限制：1秒 空间限制：32768K 热度指数：24425

题目描述

Sort a linked list using insertion sort.（插入排序）


 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
实现了两个插入排序，一个是新建的链表中插入，一个是原链表中插入交换

重点：链表的next指针的交换，循环体的开始和结束判断比较复杂，
      其中又是循环的结束判断最容易出错，最好先画图或理好思路。
*/

/*新建的链表中插入*/
ListNode *insertionSortList(ListNode *head) {
	if (head == NULL || head->next == NULL)
		return head;
	ListNode* first = new ListNode(0);
	ListNode* index = head;
	ListNode* cur = first;
	//cur->next = index;	//第一个节点操作后来发现可以并到后面循环体
	//index = index->next;
	//cur->next->next = NULL;
	while (index != NULL) {
		cur = first;
		while (cur->next != NULL&&cur->next->val <= index->val) {
			cur = cur->next;
		}
		ListNode* temp1=cur->next;
		ListNode* temp2 = index->next;
		cur->next = index;
		index->next = temp1;
		index = temp2;
	}
	return first->next;

}



/*原链表中插入交换
*
*
ListNode* insertionSort(ListNode *head) {
	if (head == NULL || head->next == NULL)
		return head;
	ListNode* first = new ListNode(0);
	first->next = head;
	ListNode *index = head; 
	while (index->next != NULL) {
		ListNode *temp = first;
		bool flag = true;
		cout <<"index->next: " << index->next->val << endl;
		while (temp->next != index->next) {
			cout << temp->next->val <<" : "<< index->next->val << endl;
			if (temp->next->val >index->next->val) {
				ListNode* temp_index_next = index->next;
				index->next = index->next->next;
				ListNode* temp_temp_next = temp->next;
				temp->next = temp_index_next;
				temp_index_next->next = temp_temp_next;
				flag = false;
				break;
			}
			temp = temp->next;
		}
		if (flag)
			index = index->next;
	}
	return first->next;
}
*/



/*
这个是写完对比过得

//这题不是让用插入排序吗。。。评论里怎么各式各样的。。
//解释下：
// 插入排序就是不断的向一个已经排序的列表中(此处为代码中的sortedList)添加新的节点，并且保证添加节点后的列表仍然有序。
//     一开始的时候sortedList为空，需要遍历输入链表（也就是未排序链表，此处为形参head）的每一个节点，每遍历一个，sortedList加一个。
//      cur代表的就是你当前要加入sortedlist的节点。cur要插入的位置在sortedList的哪里呢？就是此处代码中node的后面。 经过这么一轮，一个节点就被加入到了sortlist。之后同理。 /**
// Definition for singly-linked list.
 struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if(head==nullptr || head->next==nullptr) return head;
         
        //在插入时，有可能需要在链表头插入，为了方便，新建立个链表
        ListNode sortedList(0);
        ListNode *cur=head;
         
        while(cur){
            //因为cur的指向可能会改变，所以要预先存下cur的next，以备在下次循环时使用
            ListNode *next=cur->next;
             
            //node代表排序数组的当前节点
            //从前向后遍历排序数组的每一个节点，和当前未排序数组中的节点做比较           
            ListNode* node=&sortedList;
            while(node->next!=nullptr && node->next->val<cur->val) //以为第一个元素是0，所以从next开始
            {
                node=node->next;
            }
             
            cur->next=node->next;
            node->next=cur;
            cur=next;
        }
         
        return sortedList.next;
 
    }
};

*/