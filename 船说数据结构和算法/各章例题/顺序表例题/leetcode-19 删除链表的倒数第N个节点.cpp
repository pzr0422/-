// leetcode-19 删除链表的倒数第N个节点 （注意边界条件，使用虚拟头节点避免问题） 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if(head == NULL) return head;
	struct ListNode new_head;
	new_head.next = head;
	struct ListNode *p = &new_head, *q = p;
	for(int i = 0; i <= n; i++) q = q->next;
	while(q){
		q = q->next;
		p = p->next;
	}
	p->next = p->next->next;
	return new_head.next;
}
