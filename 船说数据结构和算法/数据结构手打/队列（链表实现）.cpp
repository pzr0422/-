// 手敲队列（链表版）（区间左闭右开） 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
typedef struct linklist{
	Node head;//头节点	
	Node *tail;
}linklist;

int emptyList(linklist *l){
	return l->head.next == NULL;
}

linklist* init_linklist(){
	linklist *l = (linklist *)malloc(sizeof(linklist));
	l->head.next = NULL;
	l->tail = &(l->head);
	return l;
}

int frontList(linklist *l){
	if(l->head.next == NULL) return -1;
	return l->head.next->data;
}

int insertTail(linklist *l, int val){
	Node *node = getNewNode(val);
	l->tail->next = node;
	l->tail = node;//改变队列尾指针的指向
	return 1;
}

int eraseHead(linklist *l){
	if(emptyList(l)) return 0;
	Node *p = l->head.next;
	l->head.next = l->head.next->next;
	if(p->next == NULL) l->tail = &(l->head); 
	free(p);
	return 1;
}  

void clear_linklist(linklist *l){
	if(l == NULL) return;
	Node *p = l->head.next, *q;
	for(; p; p = q){
		q = p->next;
		free(p);
	}
	free(l);
	return;
}

typedef struct Queue{
	linklist *l;
	int count;
	//由于链表插入，删除都有自己的特性，所以不定义head,tail了 
}Queue;

Queue* init_Queue(){
	Queue *q = (Queue *)malloc(sizeof(Queue));
	q->l = init_linklist();
	q->count = 0;
	return q;
}

int empty(Queue *q){
	return q->count == 0;	
}

int front(Queue *q){
	if(empty(q)) return -1;
	return frontList(q->l);
}

int push(Queue *q, int val){
	insertTail(q->l, val);
	q->count++;
	return 1;
}

int pop(Queue* q){
	if(empty(q)) return 0;
	eraseHead(q->l);
	q->count--;
	return 1;
}

void clear_Queue(Queue *q){
	if(q == NULL) return;
	clear_linklist(q->l);
	free(q);
	return;
}

void output_Queue(Queue *q){
	printf("Queue: ");
	Node *p = q->l->head.next;
	while(p){
		printf("%4d", p->data);
		p = p->next;
	}
	printf("\n\n");
	return ;
}

int main(void){
	srand(time(0));
	#define MAX_OP 10
	Queue *q = init_Queue();
	for(int i = 0; i < MAX_OP; i++){
		int op = rand() % 5;//当op = 0时，执行pop;当op = 1,2,3,4时，执行push
		int val = rand() % 100;
		switch(op){
			case 0:
				printf("front of the Queue: %d\n", front(q));
				pop(q);
				break;
			case 1:
			case 2:
			case 3:
			case 4:
				printf("push %d to queue\n", val);
				push(q, val);
				break;
		} 
		output_Queue(q);
	} 
	clear_Queue(q);
	return 0;
}



























