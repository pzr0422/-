// leetcode-92-反转链表2
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//方法一：非递归版 （运行较慢，4ms，仅击败38.94%的人） 
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    //链表为空或者要反转的部分只有一个节点时，链表不变 
	if(head == NULL || left == right) return head;
	struct ListNode new_head;
	new_head.next = head;
	struct ListNode* p = &new_head, *q, *left_node, *right_node, *tool;
	
	//left指向左边界前的节点 , right指向右边界后的节点 
	for(int i = 1; i < left; i++){
		p = p->next;
	}
	left_node = p;
	q = p->next;
	
	struct ListNode new_left;
	new_left.next = NULL;
	tool = q;
	for(int i = 0; i < right - left + 1; i++){
		tool = q->next;
		q->next = new_left.next;
		new_left.next = q;
		q = tool;
	}
	left_node->next = new_left.next;//1-4-3-2
	struct ListNode* find_right = new_left.next;
	while(find_right->next){
		find_right = find_right->next;
	}
	find_right->next = q;
	return new_head.next;
} 

//方法二：递归版 （新思路：两种递归过程） (用时和内存用量均比自己写的要优) 
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
	if(left == 1 && right == 1) return head;
	//第一种递归：左边界不在翻转范围内 
	if(left != 1) {
		head->next = reverseBetween(head->next, left - 1, right - 1);
		return head;
	}
	//第二种递归：左边界在翻转范围内(与反转链表1雷同)
	else{
		struct ListNode* tail = head->next, *new_head;
		new_head = reverseBetween(head->next, left, right - 1);
		head->next = tail->next;
		tail->next = head;
		return new_head; 
	} 
} 







