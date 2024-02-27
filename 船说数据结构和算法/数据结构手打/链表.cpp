// 链表手打
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_OP 7
#define DL 3
#define STR(n) #n
#define DIGIT_LEN_STR(n) "%" STR(n) "d"
typedef struct Node{
	int data;
	struct Node *next;
}Node;

Node* getNewNode(int val){
	Node *p = (Node *)malloc(sizeof(Node));
	p->data = val;
	p->next = NULL;
	return p;
}

//花活：在无头链表中使用有头链表的思想完成插入操作
Node *insert(Node *head, int pos, int val){
	Node *node = getNewNode(val);
	Node new_head;
	new_head.next = head;
	Node *p = &new_head;
	for(int i = 0; i < pos; i++) p = p->next;
	node->next = p->next;
	p->next = node;
	return new_head.next;
}

//无头链表的插入方法：pos=0时，要更新头节点 
/*
Node* insert(Node* head, int pos, int val){
	Node *p = getNewNode(val);
	//如果插入的位置是0位置
	if(pos == 0) {
		p->next = head;
		head = p;
		return head;
	}	
	Node *tool = head;
	for(int i = 1; i < pos; i++ ){
		tool = tool->next;
	}
	p->next = tool->next;
	tool->next = p;
	return head;
}
*/

void clear(Node *head){
	if(head == NULL) return;
	for(Node *p = head, *q; p ;p = q){
		q = p->next;
		free(p);
	}
	return ;
}

void output_linklist(Node *head){
    int n = 0;
    for (Node *p = head; p; p = p->next) n += 1;
    for (int i = 0; i < n; i++) {
        printf(DIGIT_LEN_STR(DL), i);
        printf("  ");
    }
    printf("\n");
    for (Node *p = head; p; p = p->next) {
        printf(DIGIT_LEN_STR(DL), p->data);
        printf("->");
    }
    printf("\n");
    return ;
}

int find(Node *head, int val){
    Node *p = head;
    int n = 0;
    while (p) {
        if (p->data == val) {
            output_linklist(head, 1);
            int len = n * (DL + 2) + 2;
            for (int i = 0; i < len; i++) printf(" ");
            printf("^\n");
            for (int i = 0; i < len; i++) printf(" ");
            printf("|\n");
            return 1;
        }
        n += 1;
        p = p->next;
    }
    return 0;
}

int main(void){
	srand(time(0));
    Node *head = NULL;
    for (int i = 0; i < MAX_OP; i++) {
        int pos = rand() % (i + 1), val = rand() % 100;
        printf("insert %d at %d to linklist\n", val, pos);
        head = insert(head, pos, val);
        output_linklist(head);
    }
    int val;
    while (~scanf("%d", &val)) {
        if (!find(head, val)) {
            printf("not found\n");
        }
    }
    clear(head);
	return 0;
} 

























