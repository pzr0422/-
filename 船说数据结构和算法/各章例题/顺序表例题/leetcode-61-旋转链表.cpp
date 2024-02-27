// leetcode-61-旋转链表
 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//自己想的（较为直接） 
struct ListNode* rotateRight(struct ListNode* head, int k) {
	int value[500] = {0};
	struct ListNode* p = head, *q = head;
	int i = 0;
	int j = 0;
	while(p){
		value[i] = p->val;
		i++;
		p = p->next;
	}
	int value_changed[500] = {0};
	for(int j = 0; j < i; j++){
		value_changed[(j+k)%i] = value[j];
	}
	while(q){
		q->val = value_changed[j];
		j++;
		q = q->next;
	}
	return head;
}

//在原链表上操作 
int getLength(struct ListNode* head){
	int len = 0;
	while(head){
		len++;
		head = head->next;
	}
	return len;
}
struct ListNode* rotateRight(struct ListNode* head, int k){
	if(head == NULL) return head;
	int n = getLength(head);
	k %= n;
	if(k == 0) return head;
	struct ListNode *p = head, *q = head;
	for(int i = 0; i <= k; i++) p = p->next;
	while(p){
		p = p->next;
		q = q->next;
	}
	p = q->next;
	q->next = NULL;
	q = p;
	while(q->next != NULL) q = q->next;
	q->next = head;
	return p;
	
}



























