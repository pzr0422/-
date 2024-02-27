//反转链表 leetcode-206
#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//非递归方法1：在原链表上操作 
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *p = head, *save1 = NULL, *save2;
	while(p){
		save2 = p->next;
		//反转操作 
		p->next = save1;
		save1 = p;
		p = save2;
	} 
	return save1;//画图理解 
}

//非递归方法2：新建一个链表 
struct ListNode* reverseList(struct ListNode* head){
	struct ListNode new_head;
	new_head.next = NULL;
	for(struct ListNode* p = head, *q; p; p = q){
		q = p->next;
		p->next = new_head.next;
		new_head.next = p;
	}
	return new_head.next;
}

//递归方法 
struct ListNode* reverseList(struct ListNode* head){
	//边界条件（空链表或只有一个节点的链表） 
	if(head == NULL || head->next == NULL) return head;
	struct ListNode* node = head->next;
	struct ListNode* new_head = reverseList(node);//获取除头节点外反转后的链表头节点位置
	head->next = node->next;
	node->next = head;
	return new_head;
}





















