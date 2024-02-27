// leetcode-142 环形链表2 （数学题思维） 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode* fast = head, *slow = head;
    int isCycle = 0;
    while(fast&&fast->next){
    	fast = fast->next->next;
    	slow = slow->next;
    	if(fast == slow){
    		isCycle = 1;
    		break;
		}
	}
	if(isCycle == 1){
		slow = head;
		while(slow != fast){
			slow = slow->next;
			fast = fast->next;
		}
	}
	if(isCycle == 0) return NULL;
	return slow;
} 
