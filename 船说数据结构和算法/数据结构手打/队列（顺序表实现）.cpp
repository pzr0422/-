// 手敲循环队列（顺序表版）（区间左闭右开） 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//提前定义顺序表及其相关操作，以便在编写队列的时候使用 
typedef struct vector{
	int *data;
	int size;
}vector;

//顺序表初始化 
vector* init_vector(int n){
	vector *v = (vector*)malloc(sizeof(vector));
	v->data = (int*)malloc(n * sizeof(int));
	v->size = n;
	return v;
}

//返回顺序表中指定位置的值 
int vectorSeek(vector* v, int pos){
	if(v == NULL) return -1;
	if(pos < 0 || pos >= v->size) return -1;
	return v->data[pos];
}

//在顺序表指定位置插入一个值 
int insertVector(vector *v, int pos, int val){
	if(pos < 0 || pos >= v->size) return 0;
	v->data[pos] = val;
	return 1;
}

//删除顺序表 
void clear_vector(vector* v){
	if(v == NULL) return ;
	free(v->data);
	free(v);
	return;
}

//队列结构定义及其操作 
typedef struct Queue{
	vector *data;
	int size;
	int count;
	int head;
	int tail;
}Queue;

//初始化队列 
Queue* init_Queue(int n){
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->data = init_vector(n);
	q->size = n;
	q->count = 0;
	q->head = 0;
	q->tail = 0;//head, tail均为0代表队列为空 
	return q;
}

//队列判空操作 
int empty(Queue* q){
	return (q->count == 0);
}

//队列判满操作
int full(Queue* q){
	return (q->count == q->size);
} 

//返回队列的第一个元素 
int front(Queue *q){
	return vectorSeek(q->data, q->head);
}

//向队尾添加元素 
int push(Queue *q, int val){
	if(full(q) || q == NULL) return 0;
	insertVector(q->data, q->tail, val);
	q->tail++;
	if(q->tail == q->size) q->tail = 0;
	q->count++;
	return 1;
}

//弹出队头元素 
int pop(Queue* q){
	if(empty(q) || q == NULL) return 0;
	q->head++;
	q->count--;
	return 1;
}

//删除队列 
void clear_Queue(Queue* q){
	if(q == NULL) return;
	clear_vector(q->data);//不能直接写free(data) 
	free(q);
	return;
}

//打印队列中的元素
void output_Queue(Queue* q){
	printf("Queue: ");
	for(int i = 0; i < q->count; i++){
		printf("%4d", vectorSeek(q->data, (q->head + i) % q->size));
	}
	printf("\n\n");
	return;
} 
int main(void){
	srand(time(0));
	#define MAX_OP 10
	Queue *q = init_Queue(5);
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












