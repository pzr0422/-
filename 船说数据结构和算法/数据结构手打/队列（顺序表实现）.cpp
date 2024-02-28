// ����ѭ�����У�˳���棩����������ҿ��� 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//��ǰ����˳�������ز������Ա��ڱ�д���е�ʱ��ʹ�� 
typedef struct vector{
	int *data;
	int size;
}vector;

//˳����ʼ�� 
vector* init_vector(int n){
	vector *v = (vector*)malloc(sizeof(vector));
	v->data = (int*)malloc(n * sizeof(int));
	v->size = n;
	return v;
}

//����˳�����ָ��λ�õ�ֵ 
int vectorSeek(vector* v, int pos){
	if(v == NULL) return -1;
	if(pos < 0 || pos >= v->size) return -1;
	return v->data[pos];
}

//��˳���ָ��λ�ò���һ��ֵ 
int insertVector(vector *v, int pos, int val){
	if(pos < 0 || pos >= v->size) return 0;
	v->data[pos] = val;
	return 1;
}

//ɾ��˳��� 
void clear_vector(vector* v){
	if(v == NULL) return ;
	free(v->data);
	free(v);
	return;
}

//���нṹ���弰����� 
typedef struct Queue{
	vector *data;
	int size;
	int count;
	int head;
	int tail;
}Queue;

//��ʼ������ 
Queue* init_Queue(int n){
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->data = init_vector(n);
	q->size = n;
	q->count = 0;
	q->head = 0;
	q->tail = 0;//head, tail��Ϊ0�������Ϊ�� 
	return q;
}

//�����пղ��� 
int empty(Queue* q){
	return (q->count == 0);
}

//������������
int full(Queue* q){
	return (q->count == q->size);
} 

//���ض��еĵ�һ��Ԫ�� 
int front(Queue *q){
	return vectorSeek(q->data, q->head);
}

//���β���Ԫ�� 
int push(Queue *q, int val){
	if(full(q) || q == NULL) return 0;
	insertVector(q->data, q->tail, val);
	q->tail++;
	if(q->tail == q->size) q->tail = 0;
	q->count++;
	return 1;
}

//������ͷԪ�� 
int pop(Queue* q){
	if(empty(q) || q == NULL) return 0;
	q->head++;
	q->count--;
	return 1;
}

//ɾ������ 
void clear_Queue(Queue* q){
	if(q == NULL) return;
	clear_vector(q->data);//����ֱ��дfree(data) 
	free(q);
	return;
}

//��ӡ�����е�Ԫ��
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
		int op = rand() % 5;//��op = 0ʱ��ִ��pop;��op = 1,2,3,4ʱ��ִ��push
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












